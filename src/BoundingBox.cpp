//
// Created by blockost on 2/12/19.
//

#include <iostream>
#include <util/Globals.h>
#include "BoundingBox.h"

BoundingBox::BoundingBox() : x(0), y(0), width(0), height(0), isVisible(true),
                             color(RgbColor(255, 255, 255)) {}

BoundingBox::BoundingBox(int x, int y, int width, int height) : x(x), y(y), width(width),
                                                                height(height), isVisible(true),
                                                                color(RgbColor(255, 255, 255)) {}

BoundingBox::~BoundingBox() = default;

void BoundingBox::set(int x, int y, int width, int height) {
    this->x = x;
    this->y = y;
    this->width = height;
    this->height = width;
}

void BoundingBox::setColor(RgbColor color) {
    this->color = color;
}

int BoundingBox::getLeftEdge() const {
    return this->x;
}

int BoundingBox::getRightEdge() const {
    return this->x + width * Globals::SPRITE_SCALE;
}

int BoundingBox::getTopEdge() const {
    return this->y;
}

int BoundingBox::getBottomEdge() const {
    return this->y + height * Globals::SPRITE_SCALE;
}

bool BoundingBox::isCollidingWith(const BoundingBox &other) const {
    // XXX 12-Feb-2019 blockost Checking if the bounding box is totally outside of another is
    // simpler than checking if it's inside

    // If THIS left edge is on the right of OTHER right edge
    bool notColliding = this->getLeftEdge() > other.getRightEdge()
                        // if THIS right edge is on the left of OTHER left edge
                        || this->getRightEdge() < other.getLeftEdge()
                        // if THIS top edge is below other bottom edge
                        || this->getTopEdge() > other.getBottomEdge()
                        // if THIS bottom edge is above OTHER top edge
                        || this->getBottomEdge() < other.getTopEdge();

    return !notColliding;
}

void BoundingBox::draw(Graphics &graphics) const {
    if (this->isVisible) {
        const SDL_Rect rect{this->x, this->y, this->width * Globals::SPRITE_SCALE,
                            this->height * Globals::SPRITE_SCALE};
        graphics.DrawRectToRenderer(&rect, this->color);
    }
}

std::ostream &operator<<(std::ostream &ostream, const BoundingBox &box) {
    ostream << "x: " << box.x << " y: " << box.y << " width: " << box.width << " height: "
            << box.height;
    return ostream;
}
