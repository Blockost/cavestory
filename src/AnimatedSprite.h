//
// Created by blockost on 1/27/19.
//

#ifndef CAVESTORY_ANIMATEDSPRITE_H
#define CAVESTORY_ANIMATEDSPRITE_H


#include <SDL_rect.h>
#include <vector>
#include <string>
#include "Graphics.h"

class AnimatedSprite {
public:

    /**
     * Default constructor.
     */
    AnimatedSprite() = default;

    /**
     * Constructor.
     */
    explicit AnimatedSprite(SDL_Texture *texture);

    /**
     * Destructor.
     */
    ~AnimatedSprite();

    /**
     * Adds a animation to the list of this sprite's animation.
     */
    void addAnimations(const std::string &animationName, int numberOfFrames, int x, int y);

    /**
     * Resets the list of animations for this sprite.
     */
    void resetAnimations();

    /**
     * Draws (copies) the current frame of the sprite to the renderer at position x and y.
     */
    void draw(Graphics &graphics, int x, int y);

    void setAnimation(const std::string &animationName);

private:
    SDL_Texture *texture{};
    int frameIndex = 0;
    std::string currentAnimation;
    std::map<std::string, std::vector<SDL_Rect>> animations;
};


#endif //CAVESTORY_ANIMATEDSPRITE_H
