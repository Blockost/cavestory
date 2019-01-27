//
// Created by blockost on 1/24/19.
//

#ifndef GRAPHICS_H
#define GRAPHICS_H


#include <string>
#include <iostream>

class Graphics {

private:
    std::string name;
    int number;

public:
    // Constructor
    Graphics(std::string, int);

    // Destructor
    virtual ~Graphics();

    void doStuff();

};


#endif //GRAPHICS_H
