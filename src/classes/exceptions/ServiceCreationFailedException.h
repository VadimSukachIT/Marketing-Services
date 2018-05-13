//
// Created by Vadim Sukach on 01.05.2018.
//

#ifndef MARKETINGSERVICES_SERVICECREATIONFAILEDEXCEPTION_H
#define MARKETINGSERVICES_SERVICECREATIONFAILEDEXCEPTION_H

#include <exception>

class ServiceCreationFailedException : public exception {
public:
    const char *what() const throw() override {
        return "\nСоздание услуги прервано.\n";
    }
};


#endif //MARKETINGSERVICES_SERVICECREATIONFAILEDEXCEPTION_H
