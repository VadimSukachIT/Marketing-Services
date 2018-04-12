//
// Created by Vadim Sukach on 11.04.2018.
//

#ifndef MARKETINGSERVICES_PERFOMEMAILDISPATCHSERVICE_H
#define MARKETINGSERVICES_PERFOMEMAILDISPATCHSERVICE_H

#include "Service.h";
#include "iostream";
#include "string";

using namespace std;

class PerformEmailDispatchService : public Service {
public:
    PerformEmailDispatchService() = default;

    ~PerformEmailDispatchService() override = default;

    void perform() override {
        cout << "Performing email dispatching..." << endl;
    }

    string getTemplate() override {
        return "EMAIL $FIRST$ $SECOND$ ...";
    }


};


#endif //MARKETINGSERVICES_PERFOMEMAILDISPATCHSERVICE_H
