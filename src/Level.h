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

    void loadMap(Graphics &graphics);

    const Tileset &getTilesetAssociatedToGid(int gid) const;
};

#endif //CAVESTORY_LEVEL_H
