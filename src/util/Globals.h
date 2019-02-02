//
// Created by blockost on 1/28/19.
//

#ifndef CAVESTORY_GLOBALS_H
#define CAVESTORY_GLOBALS_H

namespace Globals {

    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

// In cavestory, sprites are 16x16 pixels
    const int SPRITE_WIDTH = 16;
    const int SPRITE_HEIGHT = 16;

// In order to look nice, sprites should be scale by 2 (16x16 is too little)
    const int SPRITE_SCALE = 2;
}

enum Direction {
    LEFT,
    RIGHT,
    UP,
    DOWN
};

#endif //CAVESTORY_GLOBALS_H
