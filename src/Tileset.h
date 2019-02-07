//
// Created by blockost on 2/4/19.
//

#ifndef CAVESTORY_TILESET_H
#define CAVESTORY_TILESET_H


#include <string>
#include <iostream>

class Tileset {
public:

    /**
     * Constructor.
     */
    Tileset(std::string &texturePath, int firstGid, int width, int height);

    /**
     * Destructor.
     */
    ~Tileset();

    const std::string &getTexturePath() const;

    int getFirstGid() const;

    int getWidth() const;

    int getHeight() const;

    friend std::ostream &operator<<(std::ostream &ostream, const Tileset &tileset);

private:
    std::string texturePath;
    int firstGid;
    int width;
    int height;
};


#endif //CAVESTORY_TILESET_H
