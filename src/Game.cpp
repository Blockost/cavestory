//
// Created by blockost on 1/27/19.
//

#include "Game.h"

Game::Game() {
    this->graphics.createWindowAndRenderer();

    std::cout << "Loading textures..." << std::endl;
    this->graphics.loadTexture("../data/sprites/MyChar.png");
    this->graphics.loadTexture("../data/backgrounds/bkBlue.png");

    this->level = Level(this->graphics, "prtcave");
    this->player = Player(this->graphics, this->level.getPlayerSpawnPoint());

    this->startGameLoop();
}

Game::~Game() {
    SDL_Quit();
}

void Game::startGameLoop() {
    bool gameIsRunning = true;
    SDL_Event event;

    int startTimeInMs = SDL_GetTicks();
    int endTimeInMs;
    int elapsedTimeInMs;

    while (gameIsRunning) {
        if (SDL_PollEvent(&event)) {
            this->player.handleEvent(event);
            switch (event.type) {
                case SDL_KEYDOWN:
                    if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                        gameIsRunning = false;
                    }

                    break;
                case SDL_QUIT:
                    gameIsRunning = false;
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
    this->level.draw(this->graphics);
    // XXX 02-Feb-2019 blockost Player should be the last thing drawn so that it appears on top of
    // everything else
    this->player.draw(this->graphics);

    // Finally, render onto the screen
    this->graphics.render();
}

void Game::update(int elapsedTime) {
    // Player - world collisions
    this->player.handleCollisions(this->level.getBoundingBoxes());

    // Update the player
    this->player.update(elapsedTime);

    // Update the current level
    this->level.update(elapsedTime);
}