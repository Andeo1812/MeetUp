#include <iostream>

#include "PersonalData.hpp"

void PersonalData::Print() const {
    std::cout << "-------------------------------------------------------------------------" << std::endl;
    std::cout << "Personal Data" << std::endl;
    std::cout << "user_id          :---: " << user_id << std::endl;
    std::cout << "name             :---: " << name << std::endl;
    std::cout << "email            :---: " << email << std::endl;
    std::cout << "surname          :---: " << surname << std::endl;
    std::cout << "age              :---: " << date_birth << std::endl;
    std::cout << "phone_number     :---: " << phone_number << std::endl;
}
