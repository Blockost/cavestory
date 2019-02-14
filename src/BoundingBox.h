//
// Created by blockost on 2/12/19.
//

#ifndef CAVESTORY_BOUNDINGBOX_H
#define CAVESTORY_BOUNDINGBOX_H


#include <ostream>
#include "Graphics.h"

/**
 * A bounding box is a virtual rectangle that encapsultes a game element in order to detect
 * collisions with it. Top-left corner is (x, y) and bottom-right corner is (width, height)
 */
class BoundingBox {
public:

    /**
     * Default constructor.
     */
    BoundingBox();

    /**
     * Constructor.
     */
    BoundingBox(int x, int y, int width, int height);

    /**
     * Destructor.
     */
    ~BoundingBox();

    /**
     * Utility method to set all 4 coords of the bounding box.
     */
    void set(int x, int y, int width, int height);

    void setColor(RgbColor color);

    int getLeftEdge() const;

    int getRightEdge() const;

    int getTopEdge() const;

    int getBottomEdge() const;

    /**
     * Determines if current bounding box is colliding with another.
     */
    bool isCollidingWith(const BoundingBox &other) const;

    void draw(Graphics &graphics) const;

    friend std::ostream &operator<<(std::ostream &os, const BoundingBox &box);

private:
    int x, y, width, height;
    bool isVisible;
    RgbColor color;
};


#endif //CAVESTORY_BOUNDINGBOX_H
