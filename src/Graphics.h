//
// Created by blockost on 1/24/19.
//

#ifndef CAVESTORY_GRAPHICS_H
#define CAVESTORY_GRAPHICS_H


#include <string>
#include <iostream>
#include <SDL2/SDL.h>

class Graphics {

public:
    Graphics();

    virtual ~Graphics();

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
};


#endif //CAVESTORY_GRAPHICS_H
