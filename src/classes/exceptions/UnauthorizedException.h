//
// Created by Vadim Sukach on 28.04.2018.
//

#ifndef MARKETINGSERVICES_UNAUTHORIZEDEXCEPTION_H
#define MARKETINGSERVICES_UNAUTHORIZEDEXCEPTION_H


#include <exception>

class UnauthorizedException : public exception {
public:
    const char *what() const throw() override {
        return "\nОшибка. Чтобы использовать базовые команды, вам нужно зайти в свой аккаунт.\n";
    }
};


#endif //MARKETINGSERVICES_UNAUTHORIZEDEXCEPTION_H
