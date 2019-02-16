//
// Created by blockost on 2/2/19.
//

#include <sstream>
#include <fstream>

#include "Level.h"
#include "exceptions/InvalidLevelException.h"
#include "../lib/nlohmann/json.hpp"

using json = nlohmann::json;

Level::Level() = default;

Level::Level(Graphics &graphics, const std::string &mapName, Coord playerSpawnPoint) : mapSize(
        Coord(Globals::SCREEN_WIDTH, Globals::SCREEN_HEIGHT)), mapName(
        mapName) {

    this->mapTexture = graphics.getTexture("../data/backgrounds/bkBlue.png");
    this->loadMap(graphics);
}

Level::~Level() = default;

const std::vector<BoundingBox> &Level::getBoundingBoxes() {
    return this->boundingBoxes;
}

void Level::draw(Graphics &graphics) {
    for (const auto &tile : this->tiles) {
        tile.draw(graphics);
    }

    for (const auto &boundingBox: this->boundingBoxes) {
        boundingBox.draw(graphics);
    }
}

void Level::update(int elapsedTime) {}


void Level::loadMap(Graphics &graphics) {
    // TODO 03-Feb-2019 blockost Find a way to load all maps before the game starts (like we do
    // for textures

    std::stringstream ss;
    ss << "../data/maps/" << this->mapName << ".json";

    std::ifstream ifs(ss.str());
    auto jsonFile = json::parse(ifs);

    // Retrieve map size (width, height)
    const int mapWidth = jsonFile["width"];
    const int mapHeight = jsonFile["height"];

    // Retrieve tilesets texture + size (width, height)
    auto tilesets = jsonFile["tilesets"];
    for (const auto &t: tilesets) {

        // TODO 12-Feb-2019 blockost In Tiled, path to tilesets is relative to the map.
        // We should find a more elegant way for a workaround
        std::string texturePath = "../data/tilesets/" + t["image"].get<std::string>();
        int firstGid = t["firstgid"];
        int tilesetWidth = t["columns"];
        int textureHeight = t["tilecount"].get<int>() / tilesetWidth;
        Tileset tileset(texturePath, firstGid, tilesetWidth, textureHeight);

        // Load texture and store it to the list of tilesets
        graphics.loadTexture(texturePath);
        this->tilesets.push_back(std::move(tileset));
    }

    // Retrieve tiles
    auto layers = jsonFile["layers"];
    for (const auto &layer : layers) {

        // Parse collisions objects
        if (layer["name"] == "collisions") {
            auto collisionObjects = layer["objects"];
            for (const auto &collisionObject: collisionObjects) {
                this->boundingBoxes.emplace_back(BoundingBox(collisionObject["x"],
                                                             collisionObject["y"],
                                                             collisionObject["width"],
                                                             collisionObject["height"]));
            }
        } else {
            // Parse other layers (which should contain tiles only)
            auto data = layer["data"];
            int tileCounter = 0;
            for (const auto &t : data) {
                // Only store tiles whose gid != 0
                if (t != 0) {
                    Tile tile(t, tileCounter, this->getTilesetAssociatedToGid(t));
                    this->tiles.push_back(std::move(tile));
                }
                tileCounter++;
            }
        }
    }

    for (auto &tile : this->tiles) {
        tile.setPositionInTileset();
        tile.setDestinationOnMap(mapWidth);
    }
}

const Tileset &Level::getTilesetAssociatedToGid(int gid) const {
    for (const auto &tileset : this->tilesets) {
        if (gid >= tileset.getFirstGid()) {
            return tileset;
        }
    }

    throw InvalidLevelException("No tileset found!");
}
