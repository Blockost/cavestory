//
// Created by blockost on 3/9/19.
//

#ifndef CAVESTORY_ANIMATEDTILE_H
#define CAVESTORY_ANIMATEDTILE_H

#include "Tile.h"

class AnimatedTile : public Tile {

public:
    /**
     * Contructor.
     */
    AnimatedTile(unsigned tileId, unsigned positionInJson, const Tileset &tileset,
                 TileAnimation tileAnimation);

    /**
     * Destructor.
     */
    ~AnimatedTile() override;

    void draw(Graphics &graphics) const override;

    /**
     * Updates the tile based on elapsed time since last update.
     */
    void update(unsigned elaspedTime) override;

private:
    unsigned elapsedTime;
    TileAnimation animation;
};


#endif //CAVESTORY_ANIMATEDTILE_H
