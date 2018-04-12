//
// Created by Vadim Sukach on 12.04.2018.
//

#ifndef MARKETINGSERVICES_ADMIN_H
#define MARKETINGSERVICES_ADMIN_H


#include "../Role.h"
#include "string"

class Admin: public Role{
private:
    static string creationCode;

public:
    Admin() {
        role = "admin";
    };

    virtual ~Admin() {

    }

    string getRole() {
        return role;
    }

    static const string &getCreationCode() {
        return creationCode;
    }
};

string Admin::creationCode = "1234";



#endif //MARKETINGSERVICES_ADMIN_H
