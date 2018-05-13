//
// Created by Vadim Sukach on 12.04.2018.
//

#ifndef MARKETINGSERVICES_FILEMANAGER_H
#define MARKETINGSERVICES_FILEMANAGER_H

#include "iostream"
#include "fstream"
#include "../user/UserRegistry.h"
#include "../services/OrderTransportAdvert.h"
#include "../services/CreatePostersService.h"
#include "../services/PostInternetAdvertService.h"
#include "../services/PerformEmailDispatchService.h"


class FileManager {
public:
    static const string promotersFileURL;
    static const string adminsFileURL;
    static const string servicesURL;
    static const string postersURL;
    static const string emailsURL;
    static const string internetAdvertURL;
    static const string transportURL;
    template<typename T>
    static void readObjects(string);
    template<typename T>
    static string getUrlForObject(T);
    template<typename T>
    static void writeObject(T &, string);
    template<typename T>
    static void readService(string);
    template<typename T>
    static void fillAccounts(Stack<T> &, string);
    static void clearFile();
};

const string FileManager::promotersFileURL = "/Users/vadimsukach/Desktop/promoters.txt";
const string FileManager::adminsFileURL = "/Users/vadimsukach/Desktop/admins.txt";
const string FileManager::servicesURL = "/Users/vadimsukach/Desktop/services.txt";
const string FileManager::postersURL = "/Users/vadimsukach/Desktop/posters.txt";
const string FileManager::emailsURL = "/Users/vadimsukach/Desktop/emails.txt";
const string FileManager::internetAdvertURL = "/Users/vadimsukach/Desktop/advert.txt";
const string FileManager::transportURL = "/Users/vadimsukach/Desktop/transport.txt";

template<typename T>
void FileManager::fillAccounts(Stack<T> &account, string fileURL) {
    T o("a", "a");

    ifstream readFile(fileURL);
    while (readFile.read(reinterpret_cast<char *>(&o), sizeof(o))) {
        account.push(o);
    }
    readFile.close();
}

template<typename T>
void FileManager::readObjects(string fileURL) {
    T o;
    ifstream readFile(fileURL);
    while (readFile.read(reinterpret_cast<char *>(&o), sizeof(o))) {
        cout << o;
    }
    readFile.close();
}

template<typename T>
void FileManager::readService(string fileURL) {
    T o;
    ifstream readFile(fileURL);
    while (readFile.read(reinterpret_cast<char *>(&o), sizeof(o))) {
        o.output();
    }
    readFile.close();
}

template<typename T>
void FileManager::writeObject(T &o, string fileURL) {
    ifstream in(fileURL);
    std::ofstream ofs(fileURL, ios::out | ios::app);
    ofs.write(reinterpret_cast<char *>(&o), sizeof(o));
    ofs.close();
}

void FileManager::clearFile() {
    std::ofstream ofs;
    ofs.open("/Users/vadimsukach/Desktop/admins.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

template<typename T>
string FileManager::getUrlForObject(T obj) {
    OrderTransportAdvert transportService;
    CreatePostersService posterService;
    PerformEmailDispatchService emailService;
    PostInternetAdvertService advertService;

    string objectType = typeid(*obj).name();

    if (objectType == typeid(transportService).name()) {
        return FileManager::transportURL;
    } else if (objectType == typeid(posterService).name()) {
        return FileManager::postersURL;
    } else if (objectType == typeid(emailService).name()) {
        return FileManager::emailsURL;
    } else if (objectType == typeid(advertService).name()) {
        return FileManager::internetAdvertURL;
    }

}

#endif //MARKETINGSERVICES_FILEMANAGER_H
