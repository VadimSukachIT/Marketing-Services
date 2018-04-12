//
// Created by Vadim Sukach on 12.04.2018.
//

#ifndef MARKETINGSERVICES_ROLE_H
#define MARKETINGSERVICES_ROLE_H


class Role {
protected:
    string role;
public:

    virtual ~Role() {};

    virtual string getRole() = 0;
};


#endif //MARKETINGSERVICES_ROLE_H
