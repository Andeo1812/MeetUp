#include <iostream>

#include "Contacts.hpp"

void Contacts::Print() const {
    std::cout << "-------------------------------------------------------------------------" << std::endl;
    std::cout << "Contacts" << std::endl;
    std::cout << "user_id          :---: " << user_id << std::endl;
    for (std::set<std::string>::iterator it = contacts.begin(); it != contacts.end(); ++it) {
        std::cout << "contacts :---:         " << *it << std::endl;
    }
}
