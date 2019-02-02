//
// Created by blockost on 2/2/19.
//

#ifndef CAVESTORY_LEVEL_H
#define CAVESTORY_LEVEL_H


#include <util/Globals.h>
#include "Graphics.h"

class Level {
public:
    /**
     * Default constructor.
     */
    Level();

    /**
     * Constructor.
     */
    Level(Graphics &graphics, const std::string &mapName, Coord playerSpawnPoint);

    /**
     * Destructor.
     */
    ~Level();

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
};


#endif //CAVESTORY_LEVEL_H
