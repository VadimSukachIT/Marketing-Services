//
// Created by Vadim Sukach on 12.04.2018.
//

#ifndef MARKETINGSERVICES_USERLOGIN_H
#define MARKETINGSERVICES_USERLOGIN_H

#include "UserRegistry.h"
#include "../exceptions/WrongLoginException.h"
#include "../exceptions/WrongPasswordException.h"

using namespace std;

class UserLogin {
public:
    static Role *currentUser;

    static void setCurrentUser(Role);

    static void loginMenu();

    static bool checkIfLoggedUserIn();

    static void checkPassword(const string &);

    static void logout();

    template<typename T>
    static bool Login(Stack<T> &);
};

Role *UserLogin::currentUser = NULL;

void UserLogin::logout() {
    if (currentUser == NULL) {
        cout << "\nВы еще не входили в аккаунт.\n";
    } else {
        cout << "\nВы вышли из аккаунта <" + currentUser->getLogin() + ">\n";
        currentUser = NULL;
    }
}

void UserLogin::setCurrentUser(Role obj) {
    currentUser = &obj;
}

bool UserLogin::checkIfLoggedUserIn() {
    return currentUser != NULL;
}

void UserLogin::checkPassword(const string &password) {
    if (currentUser->getPassword() != password) {
        currentUser = NULL;
        throw WrongPasswordException();
    }
}

template<typename T>
bool UserLogin::Login(Stack<T> &accounts) {
    string login;
    string password;

    cout << "\nВведите логин: ";
    cin >> login;

    currentUser = accounts.findAccount(login);

    cout << "Введите пароль: ";
    cin >> password;

    string hashedPassword = UserRegistry::hashPassword(password);

    checkPassword(hashedPassword);
    cout << "\nВы вошли в аккаунт <" << currentUser->getLogin() << ">.\n";
}

void UserLogin::loginMenu() {
    int accountType;

    cout << "\n1. Зайти как промоутер.\n2. Зайти как администратор.\n3. Выйти";
    cout << "\n\nВыберите тип аккаунта: ";

    cin >> accountType;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
    }

    switch (accountType) {
        case 1:
            UserLogin::Login<Promoter>(UserRegistry::promotersAccounts);
            break;
        case 2:
            UserLogin::Login<Admin>(UserRegistry::adminsAccounts);
            break;
        case 3:
            break;
        default:
            cout << "\nНеверный ввод. " << endl;
    }

}

#endif //MARKETINGSERVICES_USERLOGIN_H
