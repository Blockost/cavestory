//
// Created by blockost on 1/24/19.
//

#include "Graphics.h"

Graphics::~Graphics() {
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
}

void Graphics::createWindowAndRenderer() {
    SDL_CreateWindowAndRenderer(640, 480, 0, &this->window, &this->renderer);
    SDL_SetWindowTitle(this->window, "Cavestory");
}

void Graphics::loadTexture(const std::string &filePath) {
    if (this->textures.count(filePath) == 0) {
        SDL_Surface *surface = IMG_Load(filePath.c_str());
        if (surface == nullptr) {
            fprintf(stderr, "Unable to load surface '%s'.", filePath.c_str());
            exit(Flags::UNABLE_TO_LOAD_SURFACE);
        }

        SDL_Texture *texture = SDL_CreateTextureFromSurface(this->renderer, surface);
        if (texture == nullptr) {
            fprintf(stderr, "Unable to convert surface to texture: %s", SDL_GetError());
            exit(Flags::UNABLE_TO_CONVERT_SURFACE_TO_TEXTURE);
        }

        SDL_FreeSurface(surface);
        this->textures[filePath] = texture;
    }
}

SDL_Texture *Graphics::getTexture(const std::string &filePath) {
    SDL_Texture *texture = this->textures[filePath];
    if (texture == nullptr) {
        fprintf(stderr, "Unable to retrieve texture '%s'. Make sure you load it first.",
                filePath.c_str());
        exit(Flags::TEXTURE_NOT_FOUND);
    }
    return this->textures[filePath];
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
