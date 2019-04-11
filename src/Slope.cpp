//
// Created by blockost on 2/24/19.
//

#include <exceptions/InvalidLevelException.h>
#include "Slope.h"

Slope::Slope(const Coord p1, const Coord p2) : isVisible(true),
                                               points(p1 * Globals::SPRITE_SCALE,
                                                      p2 * Globals::SPRITE_SCALE) {

    if (p1.x == p2.x) {
        throw InvalidLevelException("A slope object should not be a straight line");
    }

    this->slope = std::abs(p1.y - p2.y) / std::abs(p1.x - p2.x);
    this->yIntercept = p1.y - slope * p1.x;
}

Slope::~Slope() = default;

int Slope::getY(int x) const {
    return this->slope * x + this->yIntercept;
}

void Slope::draw(Graphics &graphics) const {
    if (isVisible) {
        graphics.drawLineToRenderer(this->points.first, this->points.second);
    }
}
