//
// Created by blockost on 1/28/19.
//

#include <util/Globals.h>
#include "Player.h"

Player::Player(Graphics &graphics) {

    SDL_Texture *playerTexture = graphics.getTexture("../data/sprites/MyChar.png");

    this->sprite = AnimatedSprite(playerTexture, 100);
    this->sprite.addAnimations("RunLeft", 3, 0, 0);
    this->sprite.addAnimations("RunRight", 3, 0, 16);

    // Set player's default animation
    this->setAnimation("RunRight");
}

Player::~Player() = default;

void Player::setAnimation(const std::string &animationName) {
    this->sprite.setAnimation(animationName);
}

void Player::move() {

    const int finalPosX = this->posX + this->velX;
    if (finalPosX >= 0 && finalPosX < Globals::SCREEN_WIDTH - Globals::SPRITE_WIDTH * 2) {
        this->posX = finalPosX;
    }

    const int finalPosY = this->posY + this->velY;
    if (finalPosY >= 0 && finalPosY < Globals::SCREEN_HEIGHT - Globals::SPRITE_HEIGHT * 2) {
        this->posY = finalPosY;
    }
}

void Player::handleEvent(const SDL_Event &event) {
    if (event.type == SDL_KEYDOWN && !event.key.repeat) {

        switch (event.key.keysym.scancode) {
            case SDL_SCANCODE_RIGHT:
                this->setAnimation("RunRight");
                this->velX += X_VELOCITY;
                break;
            case SDL_SCANCODE_LEFT:
                this->setAnimation("RunLeft");
                this->velX -= X_VELOCITY;
                break;
            case SDL_SCANCODE_UP:
                this->velY -= Y_VELOCITY;
                break;
            case SDL_SCANCODE_DOWN:
                this->velY += Y_VELOCITY;
                break;
            default:
                // Do nothing
                break;
        }
    }

    if (event.type == SDL_KEYUP) {
        switch (event.key.keysym.scancode) {
            case SDL_SCANCODE_RIGHT:
                this->setAnimation("RunRight");
                this->velX -= X_VELOCITY;
                break;
            case SDL_SCANCODE_LEFT:
                this->setAnimation("RunLeft");
                this->velX += X_VELOCITY;
                break;
            case SDL_SCANCODE_UP:
                this->velY += Y_VELOCITY;
                break;
            case SDL_SCANCODE_DOWN:
                this->velY -= Y_VELOCITY;
                break;
            default:
                // Do nothing
                break;
        }
    }
}

void Player::draw(Graphics &graphics) {
    this->sprite.draw(graphics, this->posX, this->posY);
}

void Player::update(float elapsedTime) {
    this->move();
    this->sprite.update(elapsedTime);
}


