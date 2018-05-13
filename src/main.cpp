#include "headers.h"
#include "algorithm"

using namespace std;

void performServices(vector<Service *> &services);

void fileManadgerMenu();

void outputServices(const vector<Service *> &services);

void writeServiceToFile(Service *const &item);

int main() {
    vector<Service *> services;
    RoleCommandAvailabilityRegistry::setServices();
    UserRegistry::fillAccounts();

    bool isCycled = true;

    cout << "МЕНЮ::" << endl;
    cout
            << "1. Показать базовые команды.\n2. Вход.\n3. Регистрация.\n4. Выход из аккаунта\n5. Менеджер файлов\n6. Выход."
            << endl << endl;
    cout << "Вы также можете вводить базовые команды." << endl;

    while (isCycled) {
        string userCommand;

        cout << "\nВведите команду: ";
        cin >> userCommand;

        int commandNumber = commandsDictionary::getCommandCode(userCommand);

        switch (commandNumber) {
            case 1:
                ServiceFactory::showCommands();
                break;
            case 2:
                try {
                    UserLogin::loginMenu();
                }
                catch (WrongLoginException &exception) {
                    cout << exception.what();
                }
                catch (WrongPasswordException &exception) {
                    cout << exception.what();
                }
                break;
            case 3:
                UserRegistry::createAccountMenu();
                break;
            case 4:
                UserLogin::logout();
                break;
            case 5:
                fileManadgerMenu();
                break;
            case 6: {
                isCycled = false;
                break;
            }
            case 7: {
                break;
            }
            case 10:
                try {
                    if (ServiceFactory::userLoggedInAndCanPerformService("run")) {
                        if (!services.empty()) {
                            performServices(services);
                        } else {
                            cout << "\nВ данный момент никаких заказов нет." << endl;
                        }
                    }
                }
                catch (UnauthorizedException &obj) {
                    cout << obj.what();
                }
                catch (NoCommandAvailabilityException &obj) {
                    cout << obj.what();
                }
                break;
            case 11: {
                try {
                    if (ServiceFactory::userLoggedInAndCanPerformService("remove")) {
                        if (!services.empty()) {
                            int index;
                            outputServices(services);

                            cout << "\nВведите номер заказа, который хотите удалить: ";
                            cin >> index;

                            if (index <= 0 || index > services.size()) {
                                cout << "\nНеверный ввод.";
                                break;
                            } else {
                                services.erase(services.begin() + index - 1);
                            }
                        } else {
                            cout << "\nВ данный момент заказов нет.\n";
                        }
                    }
                }
                catch (UnauthorizedException &obj) {
                    cout << obj.what();
                }
                catch (NoCommandAvailabilityException &obj) {
                    cout << obj.what();
                }
                break;
            }
            case 12: {
                try {
                    if (ServiceFactory::userLoggedInAndCanPerformService("change")) {
                        if (!services.empty()) {
                            int serviceIndex;

                            outputServices(services);

                            cout << "\nВведите номер заказа, который хотите изменить: ";
                            cin >> serviceIndex;

                            if (serviceIndex < 1 || serviceIndex > services.size()) {
                                cout << "\nТакого заказа нет." << endl;
                            } else {

                                vector<Service *>::iterator serviceIterator;

                                serviceIterator = services.begin() + serviceIndex - 1;

                                Service *currentService = *serviceIterator;

                                currentService->input();
                            }
                        } else {
                            cout << "\nВ данный момент заказов нет.\n";
                        }
                    }
                }
                catch (WrongInputException &obj) {
                    cout << obj.what();
                }
                catch (UnauthorizedException &obj) {
                    cout << obj.what();
                }
                catch (NoCommandAvailabilityException &obj) {
                    cout << obj.what();
                }

                break;
            }
            default:
                try {
                    services.push_back(ServiceFactory::createService(userCommand));
                    cout << "\nДобавлено в сервисы.\n";
                }
                catch (UnknownCommandExceptions &obj) {
                    cout << obj.what();
                }
                catch (UnauthorizedException &obj) {
                    cout << obj.what();
                }
                catch (NoCommandAvailabilityException &obj) {
                    cout << obj.what();
                }
                catch (ServiceCreationFailedException &obj) {
                    cout << obj.what();
                }
                break;
        }


    };

    return 0;
}

void outputServices(const vector<Service *> &services) {
    int index = 1;

    for (auto &&item:services) {
        cout << "\n" << index << ".";
        index++;
        item->output();
    }
}

void performServices(vector<Service *> &services) {
    int summaryServicesCost = 0;

    for (auto &&item:services) {
        writeServiceToFile(item);

        summaryServicesCost += item->perform();

        services.pop_back();
    }
    cout << "\nУслуги были выполнены. Общая стоимость: " << summaryServicesCost << "$" << endl;
}

void writeServiceToFile(Service *const &item) {
    switch (ServiceFactory::getObjectType(item)) {
        case 1: {
            OrderTransportAdvert obj(dynamic_cast<OrderTransportAdvert &>(*item));
            FileManager::writeObject(obj, FileManager::getUrlForObject(item));
            break;
        }
        case 2: {
            CreatePostersService obj(dynamic_cast<CreatePostersService &>(*item));
            FileManager::writeObject(obj, FileManager::getUrlForObject(item));
            break;
        }
        case 3: {
            PerformEmailDispatchService obj(dynamic_cast<PerformEmailDispatchService &>(*item));
            FileManager::writeObject(obj, FileManager::getUrlForObject(item));
            break;
        }
        case 4: {
            PostInternetAdvertService obj(dynamic_cast<PostInternetAdvertService &>(*item));
            FileManager::writeObject(obj, FileManager::getUrlForObject(item));
            break;
        }
    }
}

void fileManadgerMenu() {
    int option;
    bool isCycled = true;

    cout << "\nМЕНЕДЖЕР ФАЙЛОВ::";

    cout <<
         "\n1. Вывести интернет-рекламу."
         "\n2. Вывести почтовые ящики."
         "\n3. Вывести транспортные средства."
         "\n4. Вывести постеры."
         "\n5. Вывести существующие аккаунты."
         "\n6. Выход"
         << endl;

    while (isCycled) {

        cout << "\nВыберите команду: ";
        cin >> option;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }

        switch (option) {
            case 1:
                cout << "\nВыполненные сервисы по распространению рекламы в интернете: \n";
                FileManager::readObjects<PostInternetAdvertService>(FileManager::internetAdvertURL);
                break;
            case 2:
                cout << "\nВыполненные сервисы по рассылке рекламы на почтовые адреса: \n";
                FileManager::readObjects<PerformEmailDispatchService>(FileManager::emailsURL);
                break;
            case 3:
                cout << "\nВыполненные сервисы по заказу рекламных транспортных средств: \n";
                FileManager::readObjects<OrderTransportAdvert>(FileManager::transportURL);
                break;
            case 4:
                cout << "\nВыполненные сервисы по созданию постеров: \n";
                FileManager::readObjects<CreatePostersService>(FileManager::postersURL);
                break;
            case 5:
                UserRegistry::showAccounts();
                break;
            case 6:
                isCycled = false;
                cout << "\nМЕНЮ::" << endl;
                cout
                        << "1. Показать базовые команды.\n2. Вход.\n3. Регистрация.\n4. Выход из аккаунта\n5. Менеджер файлов\n6. Выход."
                        << endl << endl;
                cout << "Вы также можете вводить базовые команды." << endl;
                break;

            default:
                cout << "\nНеверный ввод" << endl;
                break;
        }
    }
}
