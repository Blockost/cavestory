//
// Created by blockost on 2/4/19.
//

#include "Tileset.h"

Tileset::Tileset(std::string &texturePath, int firstGid, int width, int height) : texturePath(
        texturePath), firstGid(firstGid), width(width), height(height) {}

Tileset::~Tileset() = default;

const std::string &Tileset::getTexturePath() const {
    return this->texturePath;
}

int Tileset::getFirstGid() const {
    return this->firstGid;
}

int Tileset::getWidth() const {
    return width;
}

int Tileset::getHeight() const {
    return height;
}

std::ostream &operator<<(std::ostream &ostream, const Tileset &tileset) {
    ostream << "texturePath: " << tileset.texturePath << " firstGid: " << tileset.firstGid
            << " width: " << tileset.width << " height: " << tileset.height;
    return ostream;
}
