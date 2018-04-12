//
// Created by Vadim Sukach on 11.04.2018.
//

#ifndef MARKETINGSERVICES_CREATEPOSTERSSERVICE_H
#define MARKETINGSERVICES_CREATEPOSTERSSERVICE_H

#include "iostream"
#include "string"
#include "Service.h";

class CreatePostersService : public Service {
public:
    CreatePostersService() = default;

    ~CreatePostersService() override = default;

    void perform() override {
        cout << "Creating posters..." << endl;
    }

    string getTemplate() override {
        return "POSTER $NUMBER$ $SIZE$ ... Sizes: SMALL, MEDIUM, LARGE\n";
    }
};



#endif //MARKETINGSERVICES_CREATEPOSTERSSERVICE_H
