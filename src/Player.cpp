//
// Created by blockost on 1/28/19.
//

#include <util/Globals.h>
#include "Player.h"

Player::Player(Graphics &graphics) : posX(0), posY(0), velX(0), velY(0), facingDirection(RIGHT) {

    SDL_Texture *playerTexture = graphics.getTexture("../data/sprites/MyChar.png");

    this->sprite = AnimatedSprite(playerTexture, 100);
    this->sprite.addAnimations("RunLeft", 3, 0, 0);
    this->sprite.addAnimations("RunRight", 3, 0, 16);

    this->sprite.addAnimations("IdleLeft", 1, 0, 0);
    this->sprite.addAnimations("IdleRight", 1, 0, 16);

    // Set player's default animation
    this->setAnimation("IdleRight");
    this->facingDirection = Direction::RIGHT;
}

Player::~Player() = default;

void Player::setAnimation(const std::string &animationName) {
    this->sprite.setAnimation(animationName);
}

void Player::move(float elapsedTime) {

    // XXX 02-Feb-2019 blockost Multiplying by elapsedTime is supposed to smooth movements
    // based on frame rate
    const float finalPosX = this->posX + this->velX * elapsedTime;
    if (finalPosX >= 0 && finalPosX < Globals::SCREEN_WIDTH - Globals::SPRITE_WIDTH * 2) {
        this->posX = finalPosX;
    }

    const float finalPosY = this->posY + this->velY * elapsedTime;
    if (finalPosY >= 0 && finalPosY < Globals::SCREEN_HEIGHT - Globals::SPRITE_HEIGHT * 2) {
        this->posY = finalPosY;
    }
}

void Player::handleEvent(const SDL_Event &event) {
    if (event.type == SDL_KEYDOWN && !event.key.repeat) {

        switch (event.key.keysym.scancode) {
            case SDL_SCANCODE_RIGHT:
                this->moveRight();
                break;
            case SDL_SCANCODE_LEFT:
                this->moveLeft();
                break;
            case SDL_SCANCODE_UP:
                this->moveUp();
                break;
            case SDL_SCANCODE_DOWN:
                this->moveDown();
                break;
            case SDL_SCANCODE_SPACE:
                this->jump();
            default:
                // Do nothing
                break;
        }
    }

    if (event.type == SDL_KEYUP) {
        switch (event.key.keysym.scancode) {
            case SDL_SCANCODE_RIGHT:
                this->velX -= X_VELOCITY;
                this->sprite.setAnimation("IdleRight");
                break;
            case SDL_SCANCODE_LEFT:
                this->velX += X_VELOCITY;
                this->sprite.setAnimation("IdleLeft");
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
    this->sprite.draw(graphics, static_cast<int>(this->posX), static_cast<int>(this->posY));
}

void Player::update(int elapsedTime) {
    this->applyGravity();
    this->move(elapsedTime);
    this->sprite.update(elapsedTime);
}

void Player::moveLeft() {
    this->setAnimation("RunLeft");
    this->velX -= X_VELOCITY;
    this->facingDirection = Direction::LEFT;
}

void Player::moveRight() {
    this->setAnimation("RunRight");
    this->velX += X_VELOCITY;
    this->facingDirection = Direction::RIGHT;
}

void Player::moveUp() {
    this->velY -= Y_VELOCITY;
    this->facingDirection = Direction::UP;
}

void Player::moveDown() {
    this->velY += Y_VELOCITY;
    this->facingDirection = Direction::DOWN;
}

void Player::jump() {
    this->velY -= 2 * Y_VELOCITY;
}

void Player::applyGravity() {
    if (this->velY <= Globals::GRAVITY_CAP) {
        this->velY += Globals::GRAVITY;
    } else {
        this->velY = 0;
    }
}
