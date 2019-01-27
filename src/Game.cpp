//
// Created by blockost on 1/27/19.
//

#include "Game.h"

Game::Game() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    }

    this->gameLoop();
}

Game::~Game() {
    SDL_Quit();
}

void Game::gameLoop() {
    Graphics graphics;
    SDL_Event event;
    while (true) {
        if (SDL_PollEvent(&event)) {
            this->processEvent(event);
        }
    }
}

void Game::draw(Graphics &graphics) {}

void Game::update(float elapsedTime) {}

void Game::processEvent(const SDL_Event &event) {

    switch (event.type) {
        case SDL_QUIT:
            exit(0);
        default:
            std::cout << "Unsupported event type " << event.type << std::endl;
    }
}