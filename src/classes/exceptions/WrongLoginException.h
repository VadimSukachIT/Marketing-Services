//
// Created by Vadim Sukach on 29.04.2018.
//

#ifndef MARKETINGSERVICES_WRONGLOGINEXCEPTION_H
#define MARKETINGSERVICES_WRONGLOGINEXCEPTION_H

#include <exception>

class WrongLoginException : public exception {
public:
    const char *what() const throw() override {
        return "\nТакого аккаунта не существует.\n";
    }
};


#endif //MARKETINGSERVICES_WRONGLOGINEXCEPTION_H
