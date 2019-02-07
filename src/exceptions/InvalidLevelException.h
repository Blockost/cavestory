//
// Created by blockost on 2/6/19.
//

#ifndef CAVESTORY_INVALIDLEVELEXCEPTION_H
#define CAVESTORY_INVALIDLEVELEXCEPTION_H

#include <string>
#include <exception>

class InvalidLevelException : std::exception {

public:

    /**
     * Constructor.
     */
    explicit InvalidLevelException(const std::string &message);

    const std::string &getMessage() const;

private:
    std::string message;
};


#endif //CAVESTORY_INVALIDLEVELEXCEPTION_H
