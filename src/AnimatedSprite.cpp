//
// Created by blockost on 1/27/19.
//

#include "AnimatedSprite.h"
#include "util/Globals.h"

AnimatedSprite::AnimatedSprite(SDL_Texture *texture) : texture(texture) {}

AnimatedSprite::~AnimatedSprite() = default;

void AnimatedSprite::addAnimations(const std::string &animationName, int numberOfFrames, int x,
                                   int y) {

    std::vector<SDL_Rect> sourceRectangles;

    // We leverage the fact that sprites that are part of the same animation are on the
    // same line to auto build SDL source rectangles based on a start position (x, y) and
    // sprites' width and height
    for (int i = 0; i < numberOfFrames; ++i) {
        SDL_Rect rect = {(i + x) * Globals::SPRITE_WIDTH, y, Globals::SPRITE_WIDTH,
                         Globals::SPRITE_HEIGHT};
        sourceRectangles.push_back(rect);
    }

    this->animations[animationName] = sourceRectangles;
}

void AnimatedSprite::resetAnimations() {
    this->animations.clear();
}

void AnimatedSprite::draw(Graphics &graphics, int x, int y) {
    if (this->currentAnimation.empty()) {
        fprintf(stderr, "Current animation is not defined.\n");
        fprintf(stderr, "Use AnimatedSprite::setAnimation method to select an animation first");
        exit(Flags::ANIMATION_NOT_SELECTED);
    }

    SDL_Rect sourceRect = this->animations[this->currentAnimation][this->frameIndex];
    SDL_Rect destRect = {x, y, Globals::SPRITE_WIDTH * Globals::SPRITE_SCALE,
                         Globals::SPRITE_HEIGHT * Globals::SPRITE_SCALE};

    graphics.copyToRenderer(this->texture, &sourceRect, &destRect);
}

void AnimatedSprite::setAnimation(const std::string &animationName) {
    this->currentAnimation = animationName;
}
