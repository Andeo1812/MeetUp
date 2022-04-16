#include <iostream>

#include "Group.hpp"

void Group::Print() const {
    std::cout << "-------------------------------------------------------------------------" << std::endl;
    std::cout << "Group" << std::endl;
    std::cout << "group_id         :---: " << group_id << std::endl;
    std::cout << "title            :---: " << title << std::endl;
    std::cout << "description      :---: " << description << std::endl;
    for (std::set<std::string>::iterator it = members.begin(); it != members.end(); ++it) {
        std::cout << "member           :---: " << *it << std::endl;
    }
}

bool Group::operator<(const Group &other) const {
    if (title == other.title) {
        return (members < other.members);
    }
    return (title < other.title);
}
