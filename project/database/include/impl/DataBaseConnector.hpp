#include <set>
#include <string>

#include "AddressData.hpp"
#include "Contacts.hpp"
#include "Event.hpp"
#include "GeneralData.hpp"
#include "Group.hpp"
#include "MeetUp.hpp"
#include "PersonalData.hpp"
#include "User.hpp"

#define SUCCESS     0
#define ERROR      -1

#define GLOBAL_KEY_TEST_DATABASE_CON true

namespace DatabaseConnector {
    namespace GetID {
        char* User(const std::string& nickname);

        char* Event(const Event& event);

        char* Group(const std::string& title);
    }

    namespace GetNickname {
        char* User(const std::string& user_id);
    }

    namespace Security {
        int ReWritePassword(const std::string& user_id, const std::string& password);
        int ReWriteNickname(const std::string& user_id, const std::string& nickname);
    }

    namespace GroupFun {
        int Create(const Group& group);

        int Write(const Group& group);

        int DeleteAllMembers(const std::string& group_id);

        int Delete(const std::string& group_id);

        Group GetMembers(const std::string& group_id);

        namespace Management {
            int AddMember(const std::string& member, const std::string);

            int RmMember(const std::string& member, const std::string);
        }
    }

    namespace Data {
        namespace Address {
            int CreateNull(const std::string& user_id);
            int ReWrite(const AddressData& a);
            AddressData Get(const std::string &user_id);
        }

        namespace Personal {
            int CreateNull(const std::string& user_id);
            int ReWrite(const PersonalData& a);
            PersonalData Get(const std::string &user_id);
        }

        namespace General {
            int CreateNull(const std::string& user_id);
            int ReWrite(const GeneralData& a);
            GeneralData Get(const std::string &user_id);
        }
    }

    namespace Synchro {
        std::set<std::string> Contacts(const std::string& user_id, const size_t count);

        std::set<Group> Groups(const std::string& user_id, const size_t count);

        std::set<Event> Events(const std::string& user_id, const std::string& date);
    }

    namespace RegAuth {
        int Registration(const User &user);

        int Authentication(const User &user);
    }

    namespace Contact {
        int Add(const std::string& user_id, const std::string& user_id_friend);

        int Delete(const std::string& user_id, const std::string& user_id_friend);
    }

    namespace EventFun {
        int Add(const Event& event);

        int Write(const Event& event);

        int Delete(const std::string& event_id);
    }
}
