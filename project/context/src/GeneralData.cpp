#include <iostream>

#include "GeneralData.hpp"

void GeneralData::Print() const {
    std::cout << "-------------------------------------------------------------------------" << std::endl;
    std::cout << "General Data" << std::endl;
    std::cout << "user_id          :---: " << user_id << std::endl;
    std::cout << "status           :---: " << status << std::endl;
    std::cout << "label            :---: " << tags << std::endl;
    std::cout << "description      :---: " << description << std::endl;
    std::cout << "nickname         :---: " << nickname << std::endl;
}
