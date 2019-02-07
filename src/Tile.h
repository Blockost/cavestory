//
// Created by blockost on 2/4/19.
//

#ifndef CAVESTORY_TILE_H
#define CAVESTORY_TILE_H


#include <ostream>
#include <vector>
#include <util/Globals.h>
#include "Tileset.h"
#include "Graphics.h"

class Tile {

public:

    /**
     * Constructor.
     */
    Tile(int gid, int positionInJson, Tileset tileset);

    /**
     * Destructor.
     */
    ~Tile();

    friend std::ostream &operator<<(std::ostream &os, const Tile &tile);

    /**
     * Computes and sets the original position of the tile in the tileset (in pixels).
     */
    void setPositionInTileset();

    /**
     * Computes and sets where the tile should be draw on the map (i.g on the screen).
     */
    void setDestinationOnMap(int mapWidth);

    /**
     * Draws the tile on the screen.
     */
    void draw(Graphics &graphics) const;

private:
    int gid;
    int positionInJson;
    Tileset tileset;
    Coord sourceInTileset;
    Coord destinationOnMap;
};


#endif //CAVESTORY_TILE_H
