//
// Created by Vadim Sukach on 29.04.2018.
//

#ifndef MARKETINGSERVICES_UNKNOWNCOMMANDEXCEPTIONS_H
#define MARKETINGSERVICES_UNKNOWNCOMMANDEXCEPTIONS_H

#include <exception>

class UnknownCommandExceptions : public exception {
public:
    const char *what() const throw() override {
        return "\nТакой комманды нет.\n";
    }
};


#endif //MARKETINGSERVICES_UNKNOWNCOMMANDEXCEPTIONS_H
