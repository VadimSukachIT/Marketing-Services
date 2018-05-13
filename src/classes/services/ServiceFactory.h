//
// Created by Vadim Sukach on 11.04.2018.
//

#ifndef MARKETINGSERVICES_SERVICEFACTORY_H
#define MARKETINGSERVICES_SERVICEFACTORY_H

#include "Service.h"
#include "iostream"
#include "vector"
#include "string"
#include "../user/commandsDictionary.h"
#include "../user/UserLogin.h"
#include "../exceptions/UnauthorizedException.h"
#include "../exceptions/NoCommandAvailabilityException.h"
#include "../exceptions/WrongEmailException.h"
#include "../exceptions/UnknownCommandExceptions.h"
#include <regex>
#include "../exceptions/ServiceCreationFailedException.h"
#include "../exceptions/WrongInputException.h"
#include "OrderTransportAdvert.h"


class ServiceFactory {
public:

    ServiceFactory();

    ~ServiceFactory();

    static Service *createPoster();

    static Service *createEmailDispatch();

    static Service *createInternetAdvert();

    static Service *createService(string serviceName);

    static Service *createOrderTransport();

    static void showCommands();

    static bool userLoggedInAndCanPerformService(string);

    static string choosePosterSize();

    static string chooseTransportType();

    template<typename T>
    static int getObjectType(T);
};

ServiceFactory::~ServiceFactory() = default;

ServiceFactory::ServiceFactory(){};

template<typename T>
int ServiceFactory::getObjectType(T obj) {
    OrderTransportAdvert transportService;
    CreatePostersService posterService;
    PerformEmailDispatchService emailService;
    PostInternetAdvertService advertService;

    string objectType = typeid(*obj).name();

    if (objectType == typeid(transportService).name()) {
        return 1;
    } else if (objectType == typeid(posterService).name()) {
        return 2;
    } else if (objectType == typeid(emailService).name()) {
        return 3;
    } else if (objectType == typeid(advertService).name()) {
        return 4;
    }

}

bool ServiceFactory::userLoggedInAndCanPerformService(string command) {
    if (!UserLogin::checkIfLoggedUserIn()) {
        throw UnauthorizedException();
    } else if (!RoleCommandAvailabilityRegistry::canPerformService(UserLogin::currentUser->getRole(), command)) {
        throw NoCommandAvailabilityException();
    } else {
        return true;
    }

}

void ServiceFactory::showCommands() {
    cout << "\nВведите <advert>, чтобы заказать рекламу в интернете."
         << "\nВведите <email>, чтобы произвести email-рассылку."
         << "\nВведите <poster>, для создания постеров."
         << "\nВведите <transport>, чтобы заказать рекламу на транспортных средствах."
         << "\nВведите <run>, чтобы начать выполнение услуг. (Доступно только администраторам)"
         << "\nВведите <remove>, чтобы удалить услугу. (Доступно только администраторам)"
         << "\nВведите <change>, чтобы редактировать услуги\n";

}

Service *ServiceFactory::createService(string serviceName) {
    try {
        if (userLoggedInAndCanPerformService("poster")) {
            if (serviceName == "email") {
                return createEmailDispatch();
            } else if (serviceName == "poster") {
                return createPoster();
            } else if (serviceName == "advert") {
                return createInternetAdvert();
            } else if (serviceName == "transport") {
                return createOrderTransport();
            } else {
                throw UnknownCommandExceptions();
            }
        }
    }
    catch (WrongLoginException &obj) {
        cout << obj.what();
        throw ServiceCreationFailedException();
    }
    catch (WrongInputException &obj) {
        cout << obj.what();
        throw ServiceCreationFailedException();
    }
}

Service *ServiceFactory::createPoster() {
    string posterSizeType;
    int numberOfPosters;

    posterSizeType = choosePosterSize();

    if (!posterSizeType.empty()) {
        cout << "Введите количество постеров: ";

        cin >> numberOfPosters;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            throw WrongInputException();
        } else {
            return new CreatePostersService(posterSizeType, numberOfPosters);
        }
    }
}

string ServiceFactory::choosePosterSize() {
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
                posterSizeType = "больших";
                isCycled = false;
                break;
            case 2:
                posterSizeType = "средних";
                isCycled = false;
                break;
            case 3:
                posterSizeType = "маленьких";
                isCycled = false;
                break;
            default:
                cout << "Неверный ввод. Выберите один из предложенных выше вариантов:";
                break;
        }
    } while (isCycled);
    return posterSizeType;
}

Service *ServiceFactory::createEmailDispatch() {
    bool isCycled = true;
    regex emailRegex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    string email;
    vector<string> emails;

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

    return new PerformEmailDispatchService(emails);
}

Service *ServiceFactory::createInternetAdvert() {
    int option = 1;

    vector<string> typesOfInternetAdvert;

    cout
            << "\n"
               "1. Медийная интернет-реклама - 200$\n"
               "2. Рекламные баннеры - 100$\n"
               "3. Фрейм - реклама - 100$\n"
               "4. Реклама в приложениях - 300$\n"
               "Введите 0, чтобы закончить\n"
               "\nПоочерёдно вводите желаемые виды интернет - рекламы\n";


    while (option != 0) {
        bool isTypeAlreadyAdded = false;

        cout << "Ввод: ";

        cin >> option;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }

        switch (option) {
            case 1:
                for (auto &&item:typesOfInternetAdvert) {
                    if (item == "медиа") {
                        cout << "\nВы уже добавили медиа.\n";
                        isTypeAlreadyAdded = true;
                    }
                }
                if (!isTypeAlreadyAdded) {
                    typesOfInternetAdvert.emplace_back("медиа");
                }
                break;
            case 2:
                for (auto &&item:typesOfInternetAdvert) {
                    if (item == "баннеры") {
                        cout << "\nВы уже добавили баннеры.\n";
                        isTypeAlreadyAdded = true;
                    }
                }
                if (!isTypeAlreadyAdded) {
                    typesOfInternetAdvert.emplace_back("баннеры");
                }
                break;
            case 3:
                for (auto &&item:typesOfInternetAdvert) {
                    if (item == "фрейм") {
                        cout << "\nВы уже добавили фрейм-рекламу.\n";
                        isTypeAlreadyAdded = true;
                    }
                }
                if (!isTypeAlreadyAdded) {
                    typesOfInternetAdvert.emplace_back("фрейм");
                }
                break;
            case 4:
                for (auto &&item:typesOfInternetAdvert) {
                    if (item == "приложения") {
                        cout << "\nВы уже добавили приложения.\n";
                        isTypeAlreadyAdded = true;
                    }
                }
                if (!isTypeAlreadyAdded) {
                    typesOfInternetAdvert.emplace_back("приложения");
                }
                break;
            case 0:
                break;
            default:
                cout << "\nНеверный ввод\n";
        }
    }

    return new
            PostInternetAdvertService(typesOfInternetAdvert);
}

Service *ServiceFactory::createOrderTransport() {
    string transportType = chooseTransportType();

    int transportsNumber;
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

    return new OrderTransportAdvert(transportType, transportsNumber);
}

string ServiceFactory::chooseTransportType() {
    int option;
    string transportType;

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
                transportType = "самолёт";
                break;
            case 2:
                transportType = "грузовик";
                break;
            case 3:
                transportType = "машина";
                break;
            default:
                cout << "\nНеверный ввод.";
        }
    } while (transportType.empty());

    return transportType;
}

#endif //MARKETINGSERVICES_SERVICEFACTORY_H
