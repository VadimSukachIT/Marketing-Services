//
// Created by Vadim Sukach on 11.05.2018.
//

#ifndef MARKETINGSERVICES_HEADERS_H
#define MARKETINGSERVICES_HEADERS_H
#include <iostream>
#include "string"
#include "classes/containers/Stack.h"
#include "classes/services/PerformEmailDispatchService.h"
#include "classes/services/CreatePostersService.h"
#include "classes/services/PostInternetAdvertService.h"
#include "vector"
#include "map";
#include "classes/user/commandsDictionary.h"
#include "classes/user/Role.h"
#include "classes/user/RoleCommandAvailabilityRegistry.h"
#include "classes/user/Admin.h"
#include "classes/user/Promoter.h";
#include "classes/user/UserRegistry.h"
#include "classes/services/ServiceFactory.h"
#include "classes/user/UserLogin.h"
#include "classes/exceptions/UnauthorizedException.h"
#include "classes/exceptions/NoCommandAvailabilityException.h"
#include "classes/exceptions/UnknownCommandExceptions.h"
#include "classes/exceptions/WrongLoginException.h"
#include "classes/exceptions/WrongPasswordException.h"
#include "classes/exceptions/UnauthorizedException.h"
#include <typeinfo>
#endif //MARKETINGSERVICES_HEADERS_H
