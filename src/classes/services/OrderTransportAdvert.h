//
// Created by Vadim Sukach on 02.05.2018.
//

#ifndef MARKETINGSERVICES_ORDERTRANSPORTADVERT_H
#define MARKETINGSERVICES_ORDERTRANSPORTADVERT_H

#include "iostream"
#include "Service.h"

class OrderTransportAdvert : public Service {
private:
    string transportType;
    int transportsNumber;
    int serviceCost;
public:
    OrderTransportAdvert();

    OrderTransportAdvert(string, int);

    int perform() override;

    string getTemplate() override;

    void setCost();

    void output();

    int getTotalCost();

    virtual ~OrderTransportAdvert();

    void input() override;

    OrderTransportAdvert(const OrderTransportAdvert &);

    friend ostream &operator<<(ostream &, const OrderTransportAdvert);

};


OrderTransportAdvert::OrderTransportAdvert() {};
OrderTransportAdvert::OrderTransportAdvert(string transportType, int transportsNumber)  {
    this->transportType = transportType;
    this->transportsNumber = transportsNumber;
    setCost();
}
int OrderTransportAdvert::perform()  {
    string transportOutputType;
    int serviceCost;
    setCost();
    serviceCost = getTotalCost();

    cout << "\nЗаказываем " << transportsNumber << " " << transportType << " с рекламой. Общая стоимость: "
         << serviceCost << "$" << endl;
    return serviceCost;
}
string OrderTransportAdvert::getTemplate()  {
    return "transport";
}
void OrderTransportAdvert::setCost() {
    if (this->transportType == "машина") {
        serviceCost = 500;
        this->transportType = "машин";
    } else if (this->transportType == "самолёт") {
        serviceCost = 2000;
        this->transportType = "самолётов";
    } else if (this->transportType == "грузовик") {
        serviceCost = 1000;
        this->transportType = "грузовиков";
    }
}
void OrderTransportAdvert::output() {
    cout << "Сервис по заказу " << transportsNumber << " " << transportType << " для рекламы. Общая стоимость: "
         << getTotalCost() << "$";
}
int OrderTransportAdvert::getTotalCost(){
    return serviceCost * transportsNumber;
}
OrderTransportAdvert::~OrderTransportAdvert()  {};
void OrderTransportAdvert::input()  {
    int option;
    cout << "\n1. Самолет - 2000$\n2. Грузовик - 1000$\n3. Машина - 500$" << endl;

    do {
        cout << "\nВыберите вид транспорта, на котором будет реклама: ";

        cin >> option;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }

        switch (option) {
            case 1:
                transportType = "самолётов";
                break;
            case 2:
                transportType = "грузовиков";
                break;
            case 3:
                transportType = "машин";
                break;
            default:
                cout << "\nНеверный ввод.";
        }
    } while (transportType.empty());

    bool incorrectInput = true;

    do {
        cout << "\nВведите количество транспортных средств: ";
        cin >> transportsNumber;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');

            cout << "\nНеверный ввод. Попробуйте еще раз.";
        } else {
            incorrectInput = false;
        }
    } while (incorrectInput);
}
OrderTransportAdvert:: OrderTransportAdvert(const OrderTransportAdvert &obj) {
    transportType = obj.transportType;
    transportsNumber = obj.transportsNumber;
    serviceCost = obj.serviceCost;
}


ostream &operator<<(ostream &out, const OrderTransportAdvert obj) {
    out << "Сервис по заказу " << obj.transportsNumber << " " << obj.transportType << " для рекламы. Общая стоимость: "
        << obj.serviceCost << "$\n";
    return out;
}


#endif //MARKETINGSERVICES_ORDERTRANSPORTADVERT_H
