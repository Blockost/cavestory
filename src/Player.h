//
// Created by blockost on 1/28/19.
//

#ifndef CAVESTORY_PLAYER_H
#define CAVESTORY_PLAYER_H

#include <string>
#include "AnimatedSprite.h"
#include "util/Globals.h"

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

    /**
     * Moves the player by updating its position (taking into account screen size).
     */
    void move(float elapsedTime);

    /**
     * Handles SDL Event related to the player.
     */
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
    constexpr static float X_VELOCITY = 0.25f;
    // Number of pixels the player can move on the Y-Axis per frame
    constexpr static float Y_VELOCITY = 0.25f;
    AnimatedSprite sprite;
    float posX = 0, posY = 0;
    float velX = 0, velY = 0;
    Direction facingDirection = Direction::LEFT;

    /**
     * Utility method to move the player to the left;
     */
    void moveLeft();

    /**
     * Utility method to move the player to the right.
     */
    void moveRight();

    /**
     * Utility method to move the player upwards.
     */
    void moveUp();

    /**
     * Utility method to move the player downwards.
     */
    void moveDown();
};


#endif //CAVESTORY_PLAYER_H
