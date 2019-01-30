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

    /**
     * Draws the player to the screen (delegating logic to the sprite).
     */
    void draw(Graphics &graphics);

private:
    AnimatedSprite sprite;
};


#endif //CAVESTORY_PLAYER_H
