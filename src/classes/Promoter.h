//
// Created by Vadim Sukach on 12.04.2018.
//

#ifndef MARKETINGSERVICES_PROMOTER_H
#define MARKETINGSERVICES_PROMOTER_H


#include "Role.h"

class Promoter: public Role{
public:
    Promoter() {
        role = "promoter";
    }

    virtual ~Promoter() = default;

    string getRole() {
        return role;
    }
};


#endif //MARKETINGSERVICES_PROMOTER_H
