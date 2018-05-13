//
// Created by Vadim Sukach on 29.04.2018.
//

#ifndef MARKETINGSERVICES_ACCOUNTALREADYEXISTEXCEPTION_H
#define MARKETINGSERVICES_ACCOUNTALREADYEXISTEXCEPTION_H

#include <exception>

class AccountAlreadyExistException : public exception {
public:
    const char *what() const throw() override {
        return "\nОшибка. Аккаунт с таким логином уже существует.\n";
    }
};


#endif //MARKETINGSERVICES_ACCOUNTALREADYEXISTEXCEPTION_H
