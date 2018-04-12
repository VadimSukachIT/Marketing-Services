//
// Created by Vadim Sukach on 11.04.2018.
//

#ifndef MARKETINGSERVICES_SERVICEFACTORY_H
#define MARKETINGSERVICES_SERVICEFACTORY_H

#include "Service.h"
#include "iostream"
#include "vector"
#include "string"
#include "commandsDictionary.h"


class ServiceFactory {
public:

    ServiceFactory() {
    };

    ~ServiceFactory() = default;

    static Service *createService(string serviceName) {
        if (serviceName == "EMAIL") {
            return new PerformEmailDispatchService();
        } else if (serviceName == "POSTER") {
            return new CreatePostersService();
        } else if (serviceName == "ADVERT") {
            return new PostInternetAdvertService();
        }
        throw 5;
    }
    static void showCommands() {
        cout << "\nThese are basic commands: " << endl;
        vector<Service *> commands;
        Service *p = new PerformEmailDispatchService;
        commands.push_back(p);
        p = new PostInternetAdvertService;
        commands.push_back(p);
        p = new CreatePostersService;
        commands.push_back(p);
        for (auto &&item:commands) {
            cout << "   " + item->getTemplate() << endl;
        }
    }

};

#endif //MARKETINGSERVICES_SERVICEFACTORY_H
