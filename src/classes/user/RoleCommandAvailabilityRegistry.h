//
// Created by Vadim Sukach on 12.04.2018.
//

#ifndef MARKETINGSERVICES_ROLECOMMANDAVAILABILITYREGISTRY_H
#define MARKETINGSERVICES_ROLECOMMANDAVAILABILITYREGISTRY_H

#include "map"
#include "vector"
#include "string"
#include "Admin.h"
#include "Role.h"
#include "Promoter.h"

class RoleCommandAvailabilityRegistry {
private:
    static map<Role*, vector<string>> ROLE_SERVICE_NAME_MAP;
public:
    static vector<string> adminServices;
    static vector<string> promoterServices;

    static void fillAdminServices() {
        adminServices.emplace_back("EMAIL");
        adminServices.emplace_back("RUN");
        adminServices.emplace_back("POSTER");
        adminServices.emplace_back("ADVERT");
        ROLE_SERVICE_NAME_MAP.insert(pair<Role*, vector<string>>(new Admin, adminServices));
    }

    static void fillPromoterServices() {
        promoterServices.emplace_back("EMAIL");
        promoterServices.emplace_back("ADVERT");
        promoterServices.emplace_back("POSTER");
        ROLE_SERVICE_NAME_MAP.insert(pair<Role*, vector<string>>(new Promoter, promoterServices));
    }

    static bool canPerfomService(Role* role, string serviceName) {
        vector<string> myVector = ROLE_SERVICE_NAME_MAP.find(role)->second;
        return  (std::find(myVector.begin(), myVector.end(), serviceName) != myVector.end());
    }
};



#endif //MARKETINGSERVICES_ROLECOMMANDAVAILABILITYREGISTRY_H
