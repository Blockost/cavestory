//
// Created by blockost on 1/28/19.
//

#include <util/Globals.h>
#include "Player.h"

Player::Player() : posX(0), posY(0), velX(0), velY(0), facingDirection(Direction::RIGHT) {}

Player::Player(Graphics &graphics) : posX(0), posY(0), velX(0), velY(0),
                                     facingDirection(Direction::RIGHT) {

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
    if (finalPosX >= 0 &&
        finalPosX < Globals::SCREEN_WIDTH - Globals::SPRITE_WIDTH * Globals::SPRITE_SCALE) {
        this->posX = finalPosX;
    }

    const float finalPosY = this->posY + this->velY * elapsedTime;
    if (finalPosY >= 0 &&
        finalPosY < Globals::SCREEN_HEIGHT - Globals::SPRITE_HEIGHT * Globals::SPRITE_SCALE) {
        this->posY = finalPosY;
    }

    // TODO 12-Feb-2019 blockost Move this statement to the Sprite class (the player class should
    // not be responsible for this)
    this->boundingBox.set(static_cast<int>(this->posX), static_cast<int>(this->posY),
                          Globals::SPRITE_WIDTH, Globals::SPRITE_HEIGHT);
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

void Player::handleCollisions(const std::vector<BoundingBox> &boundingBoxes) {
    for (const auto &bbox: boundingBoxes) {
        Side collidingSide = this->boundingBox.getCollidingSide(bbox);

        switch (collidingSide) {
            case Side::LEFT:
                this->posX = bbox.getRightEdge() + 1;
                break;
            case Side::RIGHT:
                this->posX =
                        bbox.getLeftEdge() - (Globals::SPRITE_WIDTH * Globals::SPRITE_SCALE) - 1;
                break;
            case Side::TOP:
                this->posY = bbox.getBottomEdge() + 1;
                break;
            case Side::BOTTOM:
                this->posY =
                        bbox.getTopEdge() - (Globals::SPRITE_HEIGHT * Globals::SPRITE_SCALE) - 1;
                break;
            default:
                // Not colliding
                break;
        }
    }
}

void Player::draw(Graphics &graphics) {
    this->sprite.draw(graphics, static_cast<int>(this->posX), static_cast<int>(this->posY));
    this->boundingBox.draw(graphics);
}

void Player::update(int elapsedTime) {
    // TODO 13-Feb-2019 blockost Re-enable when it's ready
    // this->applyGravity();
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
    // TODO 16-Feb-2019 blockost Rework
    if (this->velY <= Globals::GRAVITY_CAP) {
        this->velY += Globals::GRAVITY;
    } else {
        this->velY = 0;
    }
}
