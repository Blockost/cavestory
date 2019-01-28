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
    /**
     * Default constructor.
     */
    explicit Game(Graphics &graphics);

    /**
     * Destructor.
     */
    ~Game();

private:
    // Max number of frame per second
    const int FPS = 50;
    Graphics &graphics;

    void gameLoop();

    void draw(Graphics &graphics);

    void update(float elapsedTime);

    // Takes action based on incoming SDL_Event
    void processEvent(const SDL_Event &event);

};


#endif //CAVESTORY_GAME_H
