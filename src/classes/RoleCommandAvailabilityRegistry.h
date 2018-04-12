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
    map<string, vector<string>> ROLE_SERVICE_NAME_MAP;
    vector<string> adminServices;
    vector<string> promoterServices;

public:
    RoleCommandAvailabilityRegistry () {
        adminServices.emplace_back("EMAIL");
        adminServices.emplace_back("RUN");
        adminServices.emplace_back("POSTER");
        adminServices.emplace_back("ADVERT");
        ROLE_SERVICE_NAME_MAP.insert(pair<string, vector<string>>("admin", adminServices));

        promoterServices.emplace_back("EMAIL");
        promoterServices.emplace_back("ADVERT");
        promoterServices.emplace_back("POSTER");
        ROLE_SERVICE_NAME_MAP.insert(pair<string, vector<string>>("promoter", promoterServices));
    }


    bool canPerfomService(const string role, const string serviceName) {
        vector<string> myVector = ROLE_SERVICE_NAME_MAP.find(role)->second;
        return  (std::find(myVector.begin(), myVector.end(), serviceName) != myVector.end());
    }
};



#endif //MARKETINGSERVICES_ROLECOMMANDAVAILABILITYREGISTRY_H
