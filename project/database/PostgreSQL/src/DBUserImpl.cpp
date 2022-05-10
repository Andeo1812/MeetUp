#include "DBUserImpl.hpp"

int DBUserImpl::Registration(const User& user) const {
    return EXIT_SUCCESS;
}

int DBUserImpl::Authentication(const User& user) const {
    return EXIT_SUCCESS;
}

std::string DBUserImpl::GetId(const User& user) const {
    std::string res;
    return res;
}

std::string DBUserImpl::GetNickname(const User& user) const {
    std::string res;
    return res;
}
