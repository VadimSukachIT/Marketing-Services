cmake_minimum_required(VERSION 3.10)
project(MarketingServices)

set(CMAKE_CXX_STANDARD 11)

add_executable(MarketingServices src/main.cpp src/classes/Service.h src/classes/PerformEmailDispatchService.h src/classes/CreatePostersService.h src/classes/PostInternetAdvertService.h src/classes/ServiceFactory.h src/classes/MainMenu.h src/classes/commandsDictionary.h src/classes/RoleCommandAvailabilityRegistry.h src/classes/Role.h src/classes/Promoter.h src/classes/user/Admin.h src/classes/user/UserLogin.h src/classes/user/userRegistry.h src/classes/Files/FileManager.h)