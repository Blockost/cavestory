//
// Created by blockost on 1/27/19.
//

#ifndef CAVESTORY_ANIMATEDSPRITE_H
#define CAVESTORY_ANIMATEDSPRITE_H


#include <SDL_rect.h>
#include <vector>

class AnimatedSprite {
public:
    /**
     * Constructor.
     */
    explicit AnimatedSprite(std::vector<SDL_Rect> &sourceRects);

    /**
     * Destructor.
     */
    ~AnimatedSprite();

    /**
     * Retrieves the next rectangles in the animation.
     */
    SDL_Rect &next();

private:
    int counter = 0;
    unsigned long animationSize;
    std::vector<SDL_Rect> sourceRects;
};


#endif //CAVESTORY_ANIMATEDSPRITE_H
