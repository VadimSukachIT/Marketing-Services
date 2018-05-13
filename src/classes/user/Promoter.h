//
// Created by Vadim Sukach on 12.04.2018.
//

#ifndef MARKETINGSERVICES_PROMOTER_H
#define MARKETINGSERVICES_PROMOTER_H


#include "Role.h"
#include "string.h"

class Promoter : public Role {
private:
    string login;
    string password;
    string role;
public:
    Promoter();

    Promoter(string, string);

    Promoter(const Promoter &);

    string getRole();

    string getLogin();

    string getPassword();

    virtual ~Promoter() override;

    friend ostream &operator<<(ostream &, Promoter);

    friend istream &operator>>(istream &, Promoter &);
};

Promoter::Promoter() {}

Promoter::Promoter(string login, string password) {
    this->role = "promoter";
    this->login = login;
    this->password = password;
};

Promoter::Promoter(const Promoter &obj) {
    login = obj.login;
    password = obj.password;
    role = obj.role;
}

string Promoter::getRole() {
    return role;
}

string Promoter::getLogin() {
    return login;
}

string Promoter::getPassword() {
    return password;
}

Promoter::~Promoter() = default;

ostream &operator<<(ostream &out, Promoter obj) {
    out << "<" << obj.login << ">";
    return out;
}

istream &operator>>(istream &in, Promoter &obj) {
    cout << "Логин и пароль: ";
    in >> obj.login >> obj.role;
    return in;
}


#endif //MARKETINGSERVICES_PROMOTER_H
