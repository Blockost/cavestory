//
// Created by blockost on 2/2/19.
//

#ifndef CAVESTORY_LEVEL_H
#define CAVESTORY_LEVEL_H


#include <util/Globals.h>
#include <vector>
#include <ostream>

#include "Graphics.h"
#include "Tile.h"
#include "Tileset.h"
#include "BoundingBox.h"
#include "../lib/nlohmann/json.hpp"

using json = nlohmann::json;

class Level {
public:
    /**
     * Default constructor.
     */
    Level();

    /**
     * Constructor.
     */
    Level(Graphics &graphics, const std::string &mapName);

    /**
     * Destructor.
     */
    ~Level();

    /**
     * Retrieves all the bounding boxes of the current level.
     */
    const std::vector<BoundingBox> &getBoundingBoxes();

    /**
     * Retrieves player's spawn point.
     */
    const Coord &getPlayerSpawnPoint() const;

    /**
     * Sets player's spawn point to the given x and y.
     */
    void setPlayerSpawnPoint(int x, int y);

    /**
     * Draws the level on the screen.
     */
    void draw(Graphics &graphics);

    /**
     * Update level based on elapsed time since last update.
     */
    void update(int elapsedTime);


private:
    SDL_Texture *mapTexture;
    Coord mapSize = Coord(0, 0);
    std::string mapName;

    // Map of all the spawn points for the current level
    std::map<std::string, Coord> spawnPoints;

    // List of tilesets for the current level
    std::vector<Tileset> tilesets;

    // List of tiles for the current level
    std::vector<Tile> tiles;

    // List of collisions blocks for the current level
    std::vector<BoundingBox> boundingBoxes;

    // Load map from JSON file into objects
    void loadMap(Graphics &graphics);

    // Parse collision objects in the map
    void parseCollisionObjects(const json &collisionObjects);

    // Parse spawn point object in the map
    void parseSpawnPointObjects(const json &spawnPointObjects);

    // Parse slope object in the map
    void parseSlopeObjects(const json &slopeObjects);

    const Tileset &getTilesetAssociatedToGid(int gid) const;
};

#endif //CAVESTORY_LEVEL_H
