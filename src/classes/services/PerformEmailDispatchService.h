//
// Created by Vadim Sukach on 11.04.2018.
//

#ifndef MARKETINGSERVICES_PERFOMEMAILDISPATCHSERVICE_H
#define MARKETINGSERVICES_PERFOMEMAILDISPATCHSERVICE_H

#include "Service.h";
#include "iostream";
#include "string";
#include "regex"
#include <vector>

using namespace std;

class PerformEmailDispatchService : public Service {
private:
    vector<string> emails;
    int emailCost;
    int totalCost;
public:
    PerformEmailDispatchService() = default;

    PerformEmailDispatchService(const PerformEmailDispatchService &);

    PerformEmailDispatchService(vector<string> &);

    ~PerformEmailDispatchService() override;

    int perform() override;

    string getTemplate();

    void output() override;

    void input();

    friend ostream &operator<<(ostream &, const PerformEmailDispatchService);

    friend istream &operator>>(istream &, PerformEmailDispatchService &);
};

PerformEmailDispatchService::~PerformEmailDispatchService() = default;

int PerformEmailDispatchService::perform() {
    cout << "\nБыла произведена рассылка на следующие почтовые ящики: " << endl;
    for (auto &&item:this->emails) {
        cout << setw(10) << item << endl;
    }

    return totalCost;
}

PerformEmailDispatchService::PerformEmailDispatchService(const PerformEmailDispatchService &obj) {
    emailCost = obj.emailCost;
    totalCost = obj.totalCost;
}

string PerformEmailDispatchService::getTemplate() {
    return "EMAIL $FIRST$ $SECOND$ ...";
}

void PerformEmailDispatchService::input() {
    int option;
    bool isCycled;
    string email;
    regex emailRegex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

    cout << "\n1. Добавить почтовый адрес.\n2. Удалить почтовый адрес.";
    cout << "\nВвод: ";
    cin >> option;


    switch (option) {
        case 1:
            cout
                    << "\nПоочерёдно вводите email'ы пользователей формата <MAILBOX@$SUBDOMAIN.TLD>\nВведите 0, чтобы закончить ввод. \n";

            while (isCycled) {
                cout << "\nВведите email: ";
                cin >> email;

                if (email == "0") {
                    isCycled = false;
                    break;
                }
                if (regex_match(email, emailRegex)) {
                    emails.push_back(email);
                } else {
                    cout << "\nНеподходящий email\n";
                }
            }
            break;
        case 2:
            int index = 1;
            int emailIndex;

            for (auto &&currentEmail:emails) {
                cout << index << ". " << currentEmail << endl;
                index++;
            }

            cout << "\nВыберите номер почтового адреса, который хотите удалить: ";
            cin >> emailIndex;

            if (emailIndex < 1 || emailIndex > emails.size()) {
                cout << "\nТакого заказа нет." << endl;
            } else {

                emails.erase(emails.begin() + emailIndex - 1);
            }

            break;
    }
}

PerformEmailDispatchService::PerformEmailDispatchService(vector<string> &emails) {
    this->emails = emails;
    this->emailCost = 5;
    totalCost = emails.size() * emailCost;
}

void PerformEmailDispatchService::output() {
    cout << "Сервис по рассылке сообщений на следующие почтовые адреса: ";
    for (auto &&item:emails) {
        cout << "\n" << item;
    }
    cout << "\nОбщая стоимость: " << this->totalCost << "$";
}

ostream &operator<<(ostream &out, const PerformEmailDispatchService obj) {
    out << "Сервис по рассылке сообщений на следующие почтовые адреса: ";
    cout << "\n1. vadim.sukach@gmail.com\n2. ihar.sukach@gmail.com\n";
    return out;
}

istream &operator>>(istream &in, PerformEmailDispatchService &obj) {
//    in >> obj.posterSizeType >> obj.numberOfPosters >> obj.totalCost;
    return in;
}

#endif //MARKETINGSERVICES_PERFOMEMAILDISPATCHSERVICE_H
