//
// Created by blockost on 1/28/19.
//

#include "Player.h"

Player::Player(Graphics &graphics) {

    SDL_Texture *playerTexture = graphics.getTexture("../data/sprites/MyChar.png");

    this->sprite = AnimatedSprite(playerTexture);
    this->sprite.addAnimations("RunLeft", 3, 0, 0);
    this->sprite.addAnimations("RunRight", 3, 0, 16);
}

Player::~Player() = default;;

void Player::setAnimation(const std::string &animationName) {
    this->sprite.setAnimation(animationName);
}

void Player::draw(Graphics &graphics) {
    this->sprite.draw(graphics, 100, 100);
}
