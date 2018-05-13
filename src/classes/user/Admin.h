//
// Created by Vadim Sukach on 12.04.2018.
//

#ifndef MARKETINGSERVICES_ADMIN_H
#define MARKETINGSERVICES_ADMIN_H


#include "Role.h"
#include "string"

class Admin : public Role {
private:
    static string creationCode;
    string login;
    string password;
    string role;
public:
    Admin();
    Admin(string, string);
    Admin(const Admin &);
    ~Admin() override;

    void setLogin(const string &);
    void setPassword(const string &);
    void setRole(const string &);

    static void setCreationCode(const string &creationCode);

    string getRole();
    string getLogin();
    string getPassword();

    static const string &getCreationCode();

    friend ostream &operator<<(ostream &, const Admin);
    friend istream &operator>>(istream &, Admin &);

};

string Admin::getRole() {
    return role;
}

string Admin::getLogin() {
    return login;
}

string Admin::getPassword() {
    return password;
}

const string &Admin::getCreationCode() {
    return creationCode;
}

string Admin::creationCode = "2257473";

void Admin::setCreationCode(const string &creationCode) {
    Admin::creationCode = creationCode;
}

void Admin::setLogin(const string &login) {
    Admin::login = login;
}

void Admin::setPassword(const string &password) {
    Admin::password = password;
}

void Admin::setRole(const string &role) {
    Admin::role = role;
}

Admin::Admin() {}

Admin::~Admin() {}

Admin::Admin(const Admin &obj) {
    login = obj.login;
    password = obj.password;
    role = obj.role;
}

Admin::Admin(string login, string password) {
    this->role = "admin";
    this->login = login;
    this->password = password;
};

ostream &operator<<(ostream &out, const Admin obj) {
    out << "<" << obj.login << ">";
    return out;
}

istream &operator>>(istream &in, Admin &obj) {
    cout << "Введите логин и пароль: ";
    in >> obj.login >> obj.password;
    return in;
}

#endif //MARKETINGSERVICES_ADMIN_H
