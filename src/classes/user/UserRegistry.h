//
// Created by Vadim Sukach on 12.04.2018.
//

#ifndef MARKETINGSERVICES_USERREGISTRY_H
#define MARKETINGSERVICES_USERREGISTRY_H

#include "../files/FileManager.h"
#include "../exceptions/AccountAlreadyExistException.h"
#include "math.h"

class UserRegistry {
public:
    static void createAccountMenu();

    static void createAdmin();

    static void createPromoter();

    static void showAccounts();

    static void fillAccounts();

    static Stack<Admin> adminsAccounts;

    static Stack<Promoter> promotersAccounts;

    static string hashPassword(string);

};

Stack<Admin> UserRegistry::adminsAccounts;
Stack<Promoter> UserRegistry::promotersAccounts;

void UserRegistry::showAccounts()  {
    cout << "\nАккаунты администраторов: \n";
    adminsAccounts.printStack();
    cout << "\nАккаунты промоутеров: \n";
    promotersAccounts.printStack();
}
void UserRegistry::fillAccounts() {
    FileManager::fillAccounts<Admin>(adminsAccounts, FileManager::adminsFileURL);
    FileManager::fillAccounts<Promoter>(promotersAccounts, FileManager::promotersFileURL);
}


string UserRegistry::hashPassword(string password){
    int i,j,k,tmp = 0;
    long a=password.length(),some = 0,st;
    string res,tmpChar,tmpRes;
    for(i = 0;i<a;i++){
        tmp = (int)password[i];
        res+=to_string(tmp);
    }
    for(i=0;i < res.length();i++){
        tmpChar = bitset<4>(stoi(res.substr(i,1))).to_string();
        k = 0;
        for(j=0;tmpChar[j]=='0';j++){
            tmpChar.erase(j,1);
            j--;
            k++;
            if(k==3)break;
        }
        tmpRes+=tmpChar;
    }
    res="";
    tmpChar="";
    tmp=0;
    for(i=0,j=0;i<tmpRes.length();i++){
        tmpChar+=tmpRes[i];
        j++;
        if(j==5){
            for(k=0,st=4;k<5;k++,st--){
                if(tmpChar[k]=='1'){
                    tmp+=pow(2,st);
                }
            }
            tmpChar = "";
            res+=to_string(tmp);
            tmp=0;
            j=0;
        }
    }
    if(tmpChar.length()!=0){
        tmp=0;
        for(k=0,st=tmpChar.length()-1;k<tmpChar.length();k++,st--){
            if(tmpChar[k]=='1'){
                tmp+=pow(2,st);
            }
        }
        res+=to_string(tmp);
    }

    if(res.find(to_string(a))!=string::npos){
        res.insert(a, "1");
    }
    else{
        res.insert(a, "0");
    }
    tmpChar = "";
    tmp=0;
    tmpRes="";
    string forThis;
    for (i=0,j=0; i<res.length(); i++) {
        tmpChar+=res[i];
        j++;
        if(j==3){
            forThis = bitset<11>(stoi(tmpChar.substr(0,3))).to_string();
            tmpChar="";
            k=0;
            for(int q = 0;forThis[q]=='0';q++){
                forThis.erase(q,1);
                q--;
                k++;
                if(k==10)break;
            }
            tmpRes+=forThis;
            j=0;
        }
    }
    if(tmpChar.length()!=0){
        forThis = bitset<11>(stoi(tmpChar.substr(0,tmpChar.length()))).to_string();
        k=0;
        for(int q = 0;forThis[q]=='0';q++){
            forThis.erase(q,1);
            q--;
            k++;
            if(k==10)break;
        }
        tmpRes+=forThis;
    }

    for(k=0,st=tmpRes.length()-1;k<tmpRes.length();k++,st--){
        if(tmpRes[k]=='1'){
            some+=pow(2,st);
        }
    }
    return res = to_string(some);
}

void UserRegistry::createAdmin() {

    string password;
    string login;
    string inputCreationCode;

    cout << "\nЧтобы зарегистрировать администратора, вам нужно ввести секретный код. Введите 0, чтобы выйти:";
    cout << "\nКод: ";

    cin >> inputCreationCode;

    if (inputCreationCode == "0") {
        return;
    } else if (inputCreationCode != Admin::getCreationCode()) {
        cout << "\nВведен неверный код\n";
    } else {
        cout << "\nВведите логин: ";
        cin >> login;
        cout << "Введите пароль: ";
        cin >> password;

        if (adminsAccounts.hasAccount(login)) {
            throw AccountAlreadyExistException();
        } else {

            string hashedPassword = hashPassword(password);

            Admin user(login, hashedPassword);

            adminsAccounts.push(user);
            FileManager::writeObject<Admin>(user, FileManager::adminsFileURL);

            cout << "\nАккаунт был создан.\n";
        }
    }
}

void UserRegistry::createPromoter() {
    string password;
    string login;
    string inputCreationCode;

    cout << "\nВведите логин: ";
    cin >> login;
    cout << "Введите пароль: ";
    cin >> password;

    if (promotersAccounts.hasAccount(login)) {
        throw AccountAlreadyExistException();
    } else {

        string hashedPassword = hashPassword(password);

        Promoter user(login, hashedPassword);

        promotersAccounts.push(user);
        FileManager::writeObject<Promoter>(user, FileManager::promotersFileURL);

        cout << "\nАккаунт был создан\n";
    }
}

void UserRegistry::createAccountMenu() {
    int option;

    cout
            << "\n1. Зарегистрировать промоутера\n2. Зарегистрировать администратора\n3. Выйти\n\nВыберите тип регистрируемого аккаунта:";
    cin >> option;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
    }

    switch (option) {
        case 2:
            try {
                createAdmin();
            }
            catch (AccountAlreadyExistException &exception) {
                cout << exception.what();
            }
            break;
        case 1:
            try {
                createPromoter();
            }
            catch (AccountAlreadyExistException &exception) {
                cout << exception.what();
            }
            break;
        case 3:
            break;
        default:
            cout << "\nНеправильный ввод.\n";
            break;
    }

};

#endif //MARKETINGSERVICES_USERREGISTRY_H
