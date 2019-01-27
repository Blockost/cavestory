//
// Created by blockost on 1/27/19.
//

#ifndef CAVESTORY_GAME_H
#define CAVESTORY_GAME_H


#include "Graphics.h"

/**
 * This class contains the logic of the main game loop.
 */
class Game {
public:
    Game();

    ~Game();

private:
    // Max number of frame per second
    const int FPS = 50;

    void gameLoop();

    void draw(Graphics &graphics);

    void update(float elapsedTime);

    void processEvent(const SDL_Event &event);

};


#endif //CAVESTORY_GAME_H
