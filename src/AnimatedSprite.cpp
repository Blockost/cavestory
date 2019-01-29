//
// Created by blockost on 1/27/19.
//

#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(std::vector<SDL_Rect> &sourceRects) : sourceRects(sourceRects) {
    this->animationSize = this->sourceRects.size();
}

AnimatedSprite::~AnimatedSprite() = default;

SDL_Rect &AnimatedSprite::next() {
    SDL_Rect &next = this->sourceRects[this->counter];
    this->counter++;

    if (this->counter >= sourceRects.size())
        this->counter = 0;

    return next;
}
