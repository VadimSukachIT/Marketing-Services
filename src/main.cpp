#include <iostream>
#include "string"
#include "classes/PerformEmailDispatchService.h"
#include "classes/CreatePostersService.h"
#include "classes/PostInternetAdvertService.h"
#include "classes/ServiceFactory.h"
#include "vector"
#include "classes/MainMenu.h"
#include "map";
#include "classes/commandsDictionary.h"
#include "classes/Role.h"
#include "classes/RoleCommandAvailabilityRegistry.h"
#include "classes/user/Admin.h"
#include "classes/Promoter.h"
#include "classes/user/UserLogin.h"
#include "classes/user/userRegistry.h"
#include "classes/Files/FileManager.h"


int getCommandCode(const string &userCommand);

using namespace std;


int main() {
    vector<Service *> services;


    bool cycleRepeat = true;

    cout << "MENU:: " << endl;
    cout << "1.Show basic commands\n2.Login \n3.Register" << endl<<endl;
    cout << "You can also type basic commands"<<endl;
    cout << "Type <RUN> to perform added services"<<endl;
    Role* user = new Promoter();
    RoleCommandAvailabilityRegistry commander;
    Admin admin;
    while (cycleRepeat) {
        string userCommand;
        cout << "\nType in command: ";
        cin >> userCommand;
        int commandNumber = getCommandCode(userCommand);

        switch (commandNumber) {
            case 1:
                ServiceFactory::showCommands();
                break;
            case 2:
                break;
            case 3:
                if (commander.canPerfomService(user->getRole(), "EMAIL") ) {
                    cout<<"YEAH";
                } else cout<<"XYI";
                break;

                break;
            case 4:
            userRegistry::createAccount();
                break;
            case 10:
                for (auto &&item:services) {
                    item->perform();
                }
                break;
            default:
                services.push_back(ServiceFactory::createService(userCommand));
                break;
        }

    };

    return 0;
}

int getCommandCode(const string &userCommand) { return commandsDictionary::getCommandCode(userCommand); }
