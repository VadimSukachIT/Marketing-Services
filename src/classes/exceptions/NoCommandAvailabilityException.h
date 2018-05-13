//
// Created by Vadim Sukach on 29.04.2018.
//

#ifndef MARKETINGSERVICES_NOCOMMANDAVAILABILITYEXCEPTION_H
#define MARKETINGSERVICES_NOCOMMANDAVAILABILITYEXCEPTION_H

#include <exception>

class NoCommandAvailabilityException : public exception {
public:
    const char *what() const throw() override {
        return "\nОшибка. Эта команда доступна только администаторам.\n";
    }
};


#endif //MARKETINGSERVICES_NOCOMMANDAVAILABILITYEXCEPTION_H
