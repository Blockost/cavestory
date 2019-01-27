//
// Created by blockost on 1/24/19.
//

#include "Graphics.h"

Graphics::Graphics(std::string name, int number) : name(std::move(name)), number(number) {
    std::cout << "Constructor called with params: name: " << this->name << ", number: "
              << this->number << std::endl;
}

Graphics::~Graphics() {
    std::cout << "Destructor called" << std::endl;
}

void Graphics::doStuff() {
    std::cout << "Doing stuff now" << std::endl;
}
