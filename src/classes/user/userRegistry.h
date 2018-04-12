//
// Created by Vadim Sukach on 12.04.2018.
//

#ifndef MARKETINGSERVICES_USERREGISTRY_H
#define MARKETINGSERVICES_USERREGISTRY_H

#include "../Files/FileManager.h"

class userRegistry {
public:
    static void createAccount();
};

void userRegistry::createAccount() {
        int option;
        cout<<"\nChoose account type:: \n.  1.Admin\n   2.Promoter"<<endl;
        cin>>option;
        switch (option) {
            case 1: {
                try {
                    string password;
                    string login;
                    string inputCreationCode;
                    cout << "First of all, enter creation code:";
                    cin >> inputCreationCode;
                    if (inputCreationCode == Admin::getCreationCode()) {
                        FileManager::writeAdminObjectToFile(login ,password);
                    } else {
                        throw 5;
                    }
                }
                catch (...) {
                    cout<<"Creation code isn't right";
                }
                break;
            }
        }
}

#endif //MARKETINGSERVICES_USERREGISTRY_H
