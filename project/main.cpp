#include <iostream>

#include "DBManagerPG.hpp"

int main(int argc, const char *argv[]) {
    std::cout << "Starting server..." << std::endl;

    User user;

    Singleton<DBManagerPG>::GetInstance().GetData().User.Registration(user);

    return EXIT_SUCCESS;
}
