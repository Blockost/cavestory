//
// Created by blockost on 2/2/19.
//

#include "Level.h"

Level::Level() = default;

Level::Level(Graphics &graphics, const std::string &mapName, Coord playerSpawnPoint) {

    // TODO 02-Feb-2019 blockost Load map based on xml tiled file
    this->mapTexture = graphics.getTexture("../data/backgrounds/bkBlue.png");
    this->mapSize = Coord(Globals::SCREEN_WIDTH, Globals::SCREEN_HEIGHT);
}

Level::~Level() = default;

void Level::draw(Graphics &graphics) {

    SDL_Rect sourceRest = {0, 0, Globals::BG_WIDTH, Globals::BG_HEIGHT};
    SDL_Rect destRect;

    for (int i = 0; i < this->mapSize.x; i += Globals::BG_WIDTH) {
        for (int j = 0; j < this->mapSize.y; j += Globals::BG_HEIGHT) {
            destRect.x = i;
            destRect.y = j;
            destRect.w = Globals::BG_WIDTH;
            destRect.h = Globals::BG_HEIGHT;
            graphics.copyToRenderer(this->mapTexture, &sourceRest, &destRect);
        }
    }
}

void Level::update(float elapsedTime) {

}
