//
// Created by Vadim Sukach on 11.04.2018.
//

#ifndef MARKETINGSERVICES_CREATEPOSTERSSERVICE_H
#define MARKETINGSERVICES_CREATEPOSTERSSERVICE_H

#include "iostream"
#include "string"
#include "../exceptions/WrongInputException.h"
#include "Service.h";

class CreatePostersService : public Service {
private:
    string posterSizeType;
    int posterCost;
    int numberOfPosters;
    int totalCost;
public:
    CreatePostersService() = default;

    CreatePostersService(string, int);

    ~CreatePostersService() override = default;

    int perform() override;

    const string &getPosterSizeType() const;

    int getPosterCost() const;

    int getNumberOfPosters() const;

    string getTemplate() override;

    void setCost(string);

    int getServiceCost();

    void output();

    void outputForFile(ostream &);

    void input() override;

    CreatePostersService(const CreatePostersService &);

    friend ostream &operator<<(ostream &, const CreatePostersService &);

    friend istream &operator>>(istream &, CreatePostersService &);


};

const string &CreatePostersService::getPosterSizeType() const {
    return posterSizeType;
}

int CreatePostersService::perform() {
    setCost(posterSizeType);
    cout << "\nСоздаются " << this->getNumberOfPosters() << " " << this->getPosterSizeType() << " постеров"
         << ": " << this->getServiceCost() << "$" << endl;
    totalCost = getServiceCost();
    return totalCost;
}

CreatePostersService::CreatePostersService(const CreatePostersService &obj) {
    posterCost = obj.posterCost;
    numberOfPosters = obj.numberOfPosters;
    totalCost = obj.totalCost;
    posterSizeType = obj.posterSizeType;
}

void CreatePostersService::output() {
    cout << "Сервис по созданию: " << numberOfPosters << " " << posterSizeType << " постеров. Общая стоимость: "
         << totalCost << "$";
}

int CreatePostersService::getServiceCost() {
    return this->getNumberOfPosters() * this->getPosterCost();

}

void CreatePostersService::outputForFile(ostream &out) {
    out << "Сервис по созданию: " << numberOfPosters << " " << posterSizeType << " постеров. Общая стоимость: "
        << totalCost << "$";
}

void CreatePostersService::setCost(string posterSizeType) {
    if (posterSizeType == "маленьких") {
        this->posterCost = 10;
        this->posterSizeType = "маленьких";
    } else if (posterSizeType == "средних") {
        this->posterCost = 30;
    } else if (posterSizeType == "больших") {
        this->posterCost = 50;
    }
}

string CreatePostersService::getTemplate() {
    return "POSTER $NUMBER$ $SIZE$ ... Sizes: SMALL, MEDIUM, LARGE\n";
}

int CreatePostersService::getNumberOfPosters() const {
    return numberOfPosters;
}

int CreatePostersService::getPosterCost() const {
    return posterCost;
}

CreatePostersService::CreatePostersService(string posterSizeType, int numberOfPosters) {
    this->posterSizeType = posterSizeType;
    this->numberOfPosters = numberOfPosters;
    setCost(posterSizeType);
    totalCost = getServiceCost();
}


ostream &operator<<(ostream &out, const CreatePostersService &obj) {
    out << "Сервис по созданию " << obj.numberOfPosters << " " << obj.posterSizeType << " постеров. Общая стоимость: "
        << obj.totalCost << "$\n";
    return out;
}

istream &operator>>(istream &in, CreatePostersService &obj) {
    in >> obj.posterSizeType >> obj.numberOfPosters >> obj.totalCost;
    return in;
}

void CreatePostersService::input() {
    bool isCycled = true;
    int posterType;
    string posterSizeType;

    cout << "\n1. Большой. 2. Средний 3. Маленький\nВведите размер постера: ";

    do {
        cin >> posterType;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }

        switch (posterType) {
            case 1:
                this->posterSizeType = "больших";
                isCycled = false;
                break;
            case 2:
                this->posterSizeType = "средних";
                isCycled = false;
                break;
            case 3:
                this->posterSizeType = "маленьких";
                isCycled = false;
                break;
            default:
                cout << "Неверный ввод. Выберите один из предложенных выше вариантов:";
                break;
        }
    } while (isCycled);

    cout << "Введите количество постеров: ";
    cin >> numberOfPosters;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        throw WrongInputException();
    }
}


#endif //MARKETINGSERVICES_CREATEPOSTERSSERVICE_H
