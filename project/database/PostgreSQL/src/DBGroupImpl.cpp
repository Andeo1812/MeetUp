#include "DBGroupImpl.hpp"

int DBGroupImpl::Create(const Group& group) const {
    return EXIT_SUCCESS;
}

int DBGroupImpl::ReWrite(const Group& group) const {
    return EXIT_SUCCESS;
}

int DBGroupImpl::DeleteAllMembers(const std::string& group_id) const {
    return EXIT_SUCCESS;
}

int DBGroupImpl::Delete(const std::string& group_id) const {
    return EXIT_SUCCESS;
}

Group DBGroupImpl::GetMembers(const std::string& group_id) const {
    Group res;
    return res;
}

int DBGroupImpl::AddMember(const std::string& user_nickname, const std::string& group_id) const {
    return EXIT_SUCCESS;
}

int DBGroupImpl::RmMember(const std::string& user_nickname, const std::string& group_id) const {
    return EXIT_SUCCESS;
}

std::string DBGroupImpl::GetId(const Group& group) const {
    std::string res;
    return res;
}
