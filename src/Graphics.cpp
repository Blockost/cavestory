//
// Created by blockost on 1/24/19.
//

#include "Graphics.h"

Graphics::Graphics() {
    SDL_CreateWindowAndRenderer(640, 480, 0, &this->window, &this->renderer);
    SDL_SetWindowTitle(this->window, "Cavestory");
}

Graphics::~Graphics() {
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
}