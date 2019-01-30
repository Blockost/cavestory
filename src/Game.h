//
// Created by blockost on 1/27/19.
//

#ifndef CAVESTORY_GAME_H
#define CAVESTORY_GAME_H


#include "Graphics.h"
#include "Player.h"

/**
 * This class contains the logic of the main game loop.
 */
class Game {
public:
    /**
     * Default constructor.
     */
    Game();

    /**
     * Destructor.
     */
    ~Game();

private:
    // Max number of frame per second
    const int FPS = 50;
    Graphics graphics;
    Player player;

    void startGameLoop();

    /**
     * This method draws everything the game needs to make appear on the screen and will be called
     * at then end of each game loop.
     */
    void draw();

    void update(float elapsedTime);

    // Takes action based on incoming SDL_Event
    void processEvent(const SDL_Event &event);

};


#endif //CAVESTORY_GAME_H
