#include <iostream>

#include "User.hpp"

void User::Print() const {
    std::cout << "-------------------------------------------------------------------------" << std::endl;
    std::cout << "User" << std::endl;
    std::cout << "user_id           :---: " << user_id << std::endl;
    std::cout << "password          :---: " << password << std::endl;
    std::cout << "nickname          :---: " << nickname << std::endl;
}
