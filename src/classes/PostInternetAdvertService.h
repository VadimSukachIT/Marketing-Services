//
// Created by Vadim Sukach on 11.04.2018.
//

#ifndef MARKETINGSERVICES_POSTINTERNETADVERTSERVICE_H
#define MARKETINGSERVICES_POSTINTERNETADVERTSERVICE_H

#include "Service.h";
#include "iostream";
using namespace std;

class PostInternetAdvertService: public Service {
public:
    PostInternetAdvertService() = default;

   ~PostInternetAdvertService() override = default;

    void perform() override {
        cout<<"Posting ad to internet.. .";
    }

    string getTemplate() override {
        return "ADVERT $AD_TYPE$";
    }
};


#endif //MARKETINGSERVICES_POSTINTERNETADVERTSERVICE_H
