//
// Created by Vadim Sukach on 29.04.2018.
//

#ifndef MARKETINGSERVICES_WRONGPASSWORDEXCEPTION_H
#define MARKETINGSERVICES_WRONGPASSWORDEXCEPTION_H


#include <exception>

class WrongPasswordException : public exception {
public:
    const char *what() const throw() override {
        return "\nНеверный пароль.\n";
    }
};


#endif //MARKETINGSERVICES_WRONGPASSWORDEXCEPTION_H
