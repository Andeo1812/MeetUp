#pragma once  //  NOLINT

#include "DBConnectionImpl.hpp"
#include "DBUserImpl.hpp"
#include "DBUserDataImpl.hpp"
#include "DBEventImpl.hpp"
#include "DBContactsImpl.hpp"
#include "DBGroupImpl.hpp"


template<typename T  = pqxx::connection, class ClassConnection = DBConnection<T>>
class DBMethods {
 public:
    DBUserImpl<ClassConnection> User;
    DBUserDataImplDefinition<ClassConnection> UserData;
    DBEventImpl<ClassConnection> Event;
    DBContactsImpl<ClassConnection> Contacts;
    DBGroupImplDefinition<ClassConnection> Group;

    DBMethods() = default;

    ~DBMethods() = default;
};
