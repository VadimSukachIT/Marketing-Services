//
// Created by Vadim Sukach on 11.04.2018.
//

#ifndef MARKETINGSERVICES_SERVICE_H
#define MARKETINGSERVICES_SERVICE_H

#include "string"
using namespace std;

class Service {
public:

    virtual ~Service(){};

    virtual int perform() = 0;

    virtual string getTemplate() = 0;

    virtual void output() = 0;

    virtual void input() = 0;
//
};


#endif //MARKETINGSERVICES_SERVICE_H
