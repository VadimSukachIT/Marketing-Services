//
// Created by Vadim Sukach on 01.05.2018.
//

#ifndef MARKETINGSERVICES_WRONGEMAILEXCEPTION_H
#define MARKETINGSERVICES_WRONGEMAILEXCEPTION_H

#include <exception>

class WrongEmailException : public exception {
public:
    const char *what() const throw() override {
        return "\nОшибка. Введенный email не соответствует шаблону.\n";
    }
};


#endif //MARKETINGSERVICES_WRONGEMAILEXCEPTION_H
