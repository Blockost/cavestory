//
// Created by blockost on 2/16/19.
//

#include "Sprite.h"

Sprite::Sprite() = default;

Sprite::Sprite(SDL_Texture *texture) : texture(texture) {

}

Sprite::~Sprite() = default;

const BoundingBox &Sprite::getBoundingBox() const {
    return this->boundingBox;
}

void Sprite::moveBoundingBox(int x, int y) {
    this->boundingBox.set(x, y);
}

void Sprite::draw(Graphics &graphics, SDL_Rect &sourceRect, int y, int x) {
    SDL_Rect destRect = {x, y, Globals::SPRITE_WIDTH * Globals::SPRITE_SCALE,
                         Globals::SPRITE_HEIGHT * Globals::SPRITE_SCALE};

    graphics.copyTextureToRenderer(this->texture, &sourceRect, &destRect);
    this->boundingBox.draw(graphics);
}