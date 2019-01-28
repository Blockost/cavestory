//
// Created by blockost on 1/27/19.
//

#include "Game.h"

Game::Game(Graphics &graphics) : graphics(graphics) {

    std::cout << "Initializing SDL subsystems..." << std::endl;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    }

    this->graphics.createWindowAndRenderer();
    std::cout << "Loading textures..." << std::endl;
    this->graphics.loadTexture("../data/sprites/MyChar.png");


    this->gameLoop();
}

Game::~Game() {
    SDL_Quit();
}

void Game::gameLoop() {
    SDL_Event event;

    SDL_Texture *texture = this->graphics.getTexture("../data/sprites/MyChar.png");
    SDL_Rect sourceRect = {0, 0, 16, 16};
    SDL_Rect destRect = {100, 100, 100, 100};
    this->graphics.copyToRenderer(texture, &sourceRect, &destRect);
    this->graphics.render();

    while (true) {
        if (SDL_PollEvent(&event)) {
            this->processEvent(event);
        }
    }
}

void Game::draw() {}

void Game::update(float elapsedTime) {}

void Game::processEvent(const SDL_Event &event) {

    switch (event.type) {
        case SDL_KEYDOWN:
            std::cout << "Key held: " << ((event.key.repeat != 0) ? "yes" : "no") << std::endl;
            std::cout << "Key pressed: " << SDL_GetScancodeName(event.key.keysym.scancode)
                      << std::endl;

            if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                exit(0);

            break;
        case SDL_QUIT:
            exit(0);
        default:
            // Do nothing for unsupported events
            break;
    }
}