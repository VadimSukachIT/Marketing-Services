//
// Created by Vadim Sukach on 11.04.2018.
//

#ifndef MARKETINGSERVICES_COMMANDSDICTIONARY_H
#define MARKETINGSERVICES_COMMANDSDICTIONARY_H

#include "string"
#include "map"

class commandsDictionary {
private:
    static map<string, int> commands;
public:

    static const map<string, int> &getCommands();

    static int getCommandCode(string &userCommand);
};

const map<string, int> & commandsDictionary::getCommands()  {
    return commands;
}

int commandsDictionary::getCommandCode(string &userCommand)  {
    std::transform(userCommand.begin(), userCommand.end(), userCommand.begin(), ::tolower);
    return commands.find(userCommand)->second;
}

map<string, int> commandsDictionary::commands = {
        {"1",      1},
        {"2",      2},
        {"3",      3},
        {"4",      4},
        {"5",      5},
        {"6",      6},
        {"7",      7},
        {"run",    10},
        {"remove", 11},
        {"change", 12},
        {"16", 16}
};

#endif //MARKETINGSERVICES_COMMANDSDICTIONARY_H
