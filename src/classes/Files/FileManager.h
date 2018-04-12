//
// Created by Vadim Sukach on 12.04.2018.
//

#ifndef MARKETINGSERVICES_FILEMANAGER_H
#define MARKETINGSERVICES_FILEMANAGER_H

#include "iostream"
#include "fstream"

class FileManager {
private:
   static ofstream toFile;
    ifstream fromFile;
public:
    static void writeAdminObjectToFile(string login, string password) {
        toFile.open("Admin.txt",ios::out | ios::app);
        toFile.write((login+" "+password).c_str(),40);
        toFile.close();
    }

    static void writePromoterObjectToFile() {

    }
};

ofstream FileManager::toFile ;

#endif //MARKETINGSERVICES_FILEMANAGER_H
