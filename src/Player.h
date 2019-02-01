//
// Created by blockost on 1/28/19.
//

#ifndef CAVESTORY_PLAYER_H
#define CAVESTORY_PLAYER_H

#include <string>
#include "AnimatedSprite.h"

class Player {
public:

    /**
     * Default constructor.
     */
    Player() = default;

    /**
     * Constructor.
     */
    explicit Player(Graphics &graphics);

    /**
     * Destructor.
     */
    ~Player();

    /**
     * Sets the given animation as the one to be played.
     */
    void setAnimation(const std::string &animationName);

    void move();

    void handleEvent(const SDL_Event &event);

    /**
     * Draws the player to the screen (delegating logic to the sprite).
     */
    void draw(Graphics &graphics);

    /**
     * Updates player based on elapsed time since last update.
     */
    void update(float elapsedTime);

private:

    // Number of pixels the player can move on the X-Axis per frame
    const static int X_VELOCITY = 1;
    // Number of pixels the player can move on the Y-Axis per frame
    const static int Y_VELOCITY = 1;

    AnimatedSprite sprite;
    int posX = 0, posY = 0;
    int velX = 0, velY = 0;
};


#endif //CAVESTORY_PLAYER_H
