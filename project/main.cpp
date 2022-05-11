#include <iostream>

#include "DBManagerPG.hpp"

int main(int argc, const char *argv[]) {
    std::cout << "Starting server..." << std::endl;

    User user;

    user.SetNickname("qqqqqqqqqqqqq");
    user.SetPassword("qqqqqqqqqqqqq");
    user.SetId("29");

    std::string res = Singleton<DBManagerPG>::GetInstance().GetData().User.GetNickname(user);

    std::cout << res << std::endl;

    return EXIT_SUCCESS;
}
