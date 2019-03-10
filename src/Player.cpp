//
// Created by blockost on 1/28/19.
//

#include "Player.h"


Player::Player(Graphics &graphics, Coord spawnPoint) : posX(0), posY(0), velX(0), velY(0),
                                                       facingDirection(Direction::RIGHT),
                                                       isGrounded(false) {

    SDL_Texture *playerTexture = graphics.getTexture("../data/sprites/MyChar.png");

    this->sprite = std::make_unique<AnimatedSprite>(playerTexture, 100);
    this->sprite->addAnimations("RunLeft", 3, 0, 0);
    this->sprite->addAnimations("RunRight", 3, 0, 16);

    this->sprite->addAnimations("IdleLeft", 1, 0, 0);
    this->sprite->addAnimations("IdleRight", 1, 0, 16);

    // Set player's default animation
    this->setAnimation("IdleRight");
    this->facingDirection = Direction::RIGHT;

    this->posX = spawnPoint.x;
    this->posY = spawnPoint.y;
}

Player::~Player() = default;

void Player::setAnimation(const std::string &animationName) {
    this->sprite->setAnimation(animationName);
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
    this->sprite->moveBoundingBox(static_cast<int>(this->posX), static_cast<int>(this->posY));
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
                this->velX = 0;
                this->sprite->setAnimation("IdleRight");
                break;
            case SDL_SCANCODE_LEFT:
                this->velX = 0;
                this->sprite->setAnimation("IdleLeft");
                break;
            default:
                // Do nothing
                break;
        }
    }
}

void Player::handleCollisions(const std::vector<BoundingBox> &boundingBoxes) {
    for (const auto &bbox: boundingBoxes) {
        const auto playerBbox = this->sprite->getBoundingBox();
        const auto collidingSide = playerBbox.getCollidingSide(bbox);

        switch (collidingSide) {
            case Side::LEFT:
                this->posX = bbox.getRightEdge() + 1;
                this->velX = 0;
                break;
            case Side::RIGHT:
                this->posX = bbox.getLeftEdge() - playerBbox.getWidth() - 1;
                this->velX = 0;
                break;
            case Side::TOP:
                this->posY = bbox.getBottomEdge() + 1;
                this->velY = 0;
                break;
            case Side::BOTTOM:
                this->posY = bbox.getTopEdge() - playerBbox.getHeight() - 1;
                this->velY = 0;
                this->isGrounded = true;
                break;
            default:
                // Not colliding
                break;
        }
    }
}

void Player::draw(Graphics &graphics) const {
    this->sprite->draw(graphics, static_cast<int>(this->posX), static_cast<int>(this->posY));
}

void Player::update(int elapsedTime) {
    this->applyGravity();
    this->move(elapsedTime);
    this->sprite->update(elapsedTime);
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

void Player::jump() {
    if (this->isGrounded) {
        this->velY -= 1.75f * Y_VELOCITY;
        this->isGrounded = false;
    }
}

void Player::applyGravity() {
    if (this->velY <= Globals::GRAVITY_CAP) {
        this->velY += Globals::GRAVITY;
    }
}
