#include <iostream>

#include "AddressData.hpp"

void AddressData::Print() const {
    std::cout << "-------------------------------------------------------------------------" << std::endl;
    std::cout << "Address Data" << std::endl;
    std::cout << "user_id          :---: " << user_id << std::endl;
    std::cout << "building         :---: " << building << std::endl;
    std::cout << "housing          :---: " << housing << std::endl;
    std::cout << "street           :---: " << street << std::endl;
    std::cout << "city             :---: " << city << std::endl;
    std::cout << "district         :---: " << district << std::endl;
    std::cout << "index            :---: " << index << std::endl;
    std::cout << "country          :---: " << country << std::endl;
}
