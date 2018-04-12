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

    static const map<string, int> &getCommands() {
        return commands;
    }

    static int getCommandCode(string stringCommand) {
        return commands.find(stringCommand)->second;
    }
};

map<string, int> commandsDictionary::commands = {
        {"1",      1},
        {"2",      2},
        {"3", 3},
        {"RUN",    10},
        {"REMOVE", 11}
};

#endif //MARKETINGSERVICES_COMMANDSDICTIONARY_H
