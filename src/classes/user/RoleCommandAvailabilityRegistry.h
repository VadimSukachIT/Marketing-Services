//
// Created by Vadim Sukach on 12.04.2018.
//

#ifndef MARKETINGSERVICES_ROLECOMMANDAVAILABILITYREGISTRY_H
#define MARKETINGSERVICES_ROLECOMMANDAVAILABILITYREGISTRY_H

#include "map"
#include "vector"
#include "string"

class RoleCommandAvailabilityRegistry {
private:
    static map<string, vector<string>> ROLE_SERVICE_NAME_MAP;
    static vector<string> adminServices;
    static vector<string> promoterServices;

public:
    static void setServices();

    static bool canPerformService(const string, const string);
};

void RoleCommandAvailabilityRegistry::setServices() {
    promoterServices.emplace_back("email");
    promoterServices.emplace_back("advert");
    promoterServices.emplace_back("poster");
    promoterServices.emplace_back("change");
    adminServices.emplace_back("transport");
    ROLE_SERVICE_NAME_MAP.insert(pair<string, vector<string>>("promoter", promoterServices));

    adminServices.emplace_back("email");
    adminServices.emplace_back("run");
    adminServices.emplace_back("remove");
    adminServices.emplace_back("change");
    adminServices.emplace_back("transport");
    adminServices.emplace_back("poster");
    adminServices.emplace_back("advert");
    ROLE_SERVICE_NAME_MAP.insert(pair<string, vector<string>>("admin", adminServices));
}

bool RoleCommandAvailabilityRegistry::canPerformService(const string role, const string serviceName) {
    vector<string> myVector = ROLE_SERVICE_NAME_MAP.find(role)->second;
    return (std::find(myVector.begin(), myVector.end(), serviceName) != myVector.end());
}

map<string, vector<string>> RoleCommandAvailabilityRegistry::ROLE_SERVICE_NAME_MAP;
vector<string> RoleCommandAvailabilityRegistry::adminServices;
vector<string> RoleCommandAvailabilityRegistry::promoterServices;


#endif //MARKETINGSERVICES_ROLECOMMANDAVAILABILITYREGISTRY_H
