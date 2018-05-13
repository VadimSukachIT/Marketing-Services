//
// Created by Vadim Sukach on 11.04.2018.
//

#ifndef MARKETINGSERVICES_POSTINTERNETADVERTSERVICE_H
#define MARKETINGSERVICES_POSTINTERNETADVERTSERVICE_H

#include "Service.h"
#include "iostream"
#include "vector"

using namespace std;

class PostInternetAdvertService : public Service {
    vector<string> advertTypes;
public:
    PostInternetAdvertService() = default;

    PostInternetAdvertService(vector<string>);

    void input() override;

    ~PostInternetAdvertService();

    int perform() override;

    string getTemplate() override;

    void output();

    int getTotalCost();

    PostInternetAdvertService(const PostInternetAdvertService &obj);

    friend ostream &operator<<(ostream &, const PostInternetAdvertService);

    friend istream &operator>>(istream &, PostInternetAdvertService &);
};

string PostInternetAdvertService::getTemplate() {
    return "ADVERT $AD_TYPE$";
}

ostream &operator<<(ostream &out, const PostInternetAdvertService obj) {
    out << "\nСервис по распространению в интернете следующих видов рекламы: \n";
    cout << "1. медиа\n2. баннеры\n3. фрейм\n4. приложения";
    return out;
}

istream &operator>>(istream &in, PostInternetAdvertService &obj) {
//    in >> obj.posterSizeType >> obj.numberOfPosters >> obj.totalCost;
    return in;
}


PostInternetAdvertService::PostInternetAdvertService(const PostInternetAdvertService &obj) {
}

int PostInternetAdvertService::getTotalCost() {
    int totalCost = 0;

    for (auto &&item:advertTypes) {
        if (item == "медиа") {
            totalCost += 200;
        } else if (item == "баннеры") {
            totalCost += 100;
        } else if (item == "фрейм") {
            totalCost += 100;
        } else if (item == "приложения") {
            totalCost += 300;
        }
    }

    return totalCost;
}

void PostInternetAdvertService::output() {
    cout << "Сервис по размещению рекламы в интернете. Задействованы следующие виды рекламы: ";
    cout << "XYI";
    for (int i = 0; i < advertTypes.size(); i++) {
        cout << advertTypes[i];
    }

    cout << "\nОбщая стоимость: " << getTotalCost() << "$";
}

int PostInternetAdvertService::perform() {
    int totalCost = getTotalCost();

    cout << "\nВы заказали рекламу следующих видов:";

    for (auto &&item:advertTypes) {
        cout << "\n" << item;
    }

    cout << "\nОбщая стоимость: " << totalCost << "$" << endl;

    return totalCost;
}

PostInternetAdvertService::~PostInternetAdvertService() {
    advertTypes.clear();
};

void PostInternetAdvertService::input() {

}

PostInternetAdvertService::PostInternetAdvertService(vector<string> advertTypes) {
    for (auto &&item:advertTypes) {
        this->advertTypes.push_back(item);
    }

}

#endif //MARKETINGSERVICES_POSTINTERNETADVERTSERVICE_H
