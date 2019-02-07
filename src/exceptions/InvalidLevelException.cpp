//
// Created by blockost on 2/6/19.
//

#include "InvalidLevelException.h"

InvalidLevelException::InvalidLevelException(const std::string &message) : message(message) {}

const std::string &InvalidLevelException::getMessage() const {
    return message;
}
