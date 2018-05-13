//
// Created by Vadim Sukach on 02.05.2018.
//

#ifndef MARKETINGSERVICES_WRONGINPUTEXCEPTION_H
#define MARKETINGSERVICES_WRONGINPUTEXCEPTION_H

#include <exception>

class WrongInputException : public exception {
public:
    const char *what() const throw() override {
        return "\nОшибка. Неверный ввод.\n";
    }
};


#endif //MARKETINGSERVICES_WRONGINPUTEXCEPTION_H
