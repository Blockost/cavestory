//
// Created by blockost on 1/27/19.
//

#include <vector>
#include <iterator>
#include <chrono>
#include "Game.h"

Game::Game() {
    this->graphics.createWindowAndRenderer();

    std::cout << "Loading textures..." << std::endl;
    this->graphics.loadTexture("../data/sprites/MyChar.png");

    this->player = Player(this->graphics);
    this->player.setAnimation("RunRight");

    this->startGameLoop();
}

Game::~Game() {
    SDL_Quit();
}

void Game::startGameLoop() {
    SDL_Event event;

    int startTimeInMs = SDL_GetTicks();
    int endTimeInMs;
    int elapsedTimeInMs;

    while (true) {
        if (SDL_PollEvent(&event)) {

            switch (event.type) {
                case SDL_KEYDOWN:
                    std::cout << "Key held: " << ((event.key.repeat != 0) ? "yes" : "no")
                              << std::endl;
                    std::cout << "Key pressed: " << SDL_GetScancodeName(event.key.keysym.scancode)
                              << std::endl;

                    // Right Arrow key
                    if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT) {
                        this->player.setAnimation("RunRight");
                    }

                    // Left Arrow key
                    if (event.key.keysym.scancode == SDL_SCANCODE_LEFT) {
                        this->player.setAnimation("RunLeft");
                    }

                    // Escape key
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

        endTimeInMs = SDL_GetTicks();
        elapsedTimeInMs = endTimeInMs - startTimeInMs;
        startTimeInMs = endTimeInMs;

        this->update(elapsedTimeInMs);
        this->draw();
    }

}

void Game::draw() {
    // Wipe the renderer
    this->graphics.clear();

    // Draw everything here
    this->player.draw(this->graphics);

    // Finally, render onto the screen
    this->graphics.render();
}

void Game::update(float elapsedTime) {
    // TODO 28-Jan-2019 blockost Update sprites/models/physics here passing elapsed time (since the
    // last update)
}

void Game::processEvent(const SDL_Event &event) {}