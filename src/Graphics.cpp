//
// Created by blockost on 1/24/19.
//

#include "Graphics.h"

Graphics::Graphics() = default;;

Graphics::~Graphics() {
    std::cout << "Destructor called" << std::endl;
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
}

void Graphics::createWindowAndRenderer() {
    SDL_CreateWindowAndRenderer(640, 480, 0, &this->window, &this->renderer);
    SDL_SetWindowTitle(this->window, "Cavestory");
}


void Graphics::loadTexture(const std::string &filePath) {
    if (textures.count(filePath) == 0) {
        SDL_Surface *surface = IMG_Load(filePath.c_str());
        // TODO 2019-27-01 blockost check if surface is not null (nullptr) here

        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);

        textures[filePath] = texture;
    }
}

SDL_Texture *Graphics::getTexture(const std::string &filePath) {
    return textures[filePath];
}


void Graphics::copyToRenderer(SDL_Texture *texture, SDL_Rect *sourceRect,
                              SDL_Rect *destRect) {
    SDL_RenderCopy(this->renderer, texture, sourceRect, destRect);
}

void Graphics::render() {
    SDL_RenderPresent(this->renderer);
}

void Graphics::clear() {
    SDL_RenderClear(this->renderer);
}
