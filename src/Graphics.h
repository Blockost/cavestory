//
// Created by blockost on 1/24/19.
//

#ifndef GRAPHICS_H
#define GRAPHICS_H


#include <string>
#include <iostream>
#include <SDL2/SDL.h>

class Graphics {

private:
    SDL_Window* window;
    SDL_Renderer* renderer;

public:
    // Constructor
    Graphics();

    // Destructor
    virtual ~Graphics();
};


#endif //GRAPHICS_H
