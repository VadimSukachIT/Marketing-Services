//
// Created by Vadim Sukach on 12.04.2018.
//

#ifndef MARKETINGSERVICES_ROLE_H
#define MARKETINGSERVICES_ROLE_H


class Role {
private:
    string login;
    string password;
    string role;
public:
    virtual ~Role() {};

    virtual string getRole() = 0;

    virtual string getLogin() = 0;

    virtual string getPassword() = 0;

    void xyi()

    void setLogin(const string &);

    void setPassword(const string &);

    void setRole(const string &);

};


void Role::setLogin(const string &login)  {
    Role::login = login;
}

void Role::setPassword(const string &password)  {
    Role::password = password;
}

void Role::setRole(const string &role)  {
    Role::role = role;
}
#endif //MARKETINGSERVICES_ROLE_H
