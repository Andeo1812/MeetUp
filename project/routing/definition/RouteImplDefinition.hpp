#pragma once  //  NOLINT

#include <memory>

#include "RouteImpl.hpp"

#include "APIKeys.hpp"

//  Processing classes
#include "HandlerContacts.hpp"
#include "HandlerEvent.hpp"
#include "HandlerGroup.hpp"
#include "HandlerMeetUp.hpp"
#include "HandlerRegAuth.hpp"
#include "HandlerSynchroClient.hpp"
#include "HandlerAddressData.hpp"
#include "HandlerGeneralData.hpp"
#include "HandlerPrivateData.hpp"
#include "HandlerPersonalData.hpp"

//  Parsing classes
#include "ParserContacts.hpp"
#include "ParserEvent.hpp"
#include "ParserGroup.hpp"
#include "ParserUser.hpp"
#include "ParserAddressData.hpp"
#include "ParserGeneralData.hpp"
#include "ParserPersonalData.hpp"
#include "ParserMeetUp.hpp"

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker, class ClassDBManager>
RouteImpl<T, ClassConnection, ClassDBMethods, ClassDBWorker, ClassDBManager>::RouteImpl() {
    //  Base            REQUEST                                        PARSER                     HANDLER
    route_map.insert({REGISTRATION,           NodeMap<T>(new const ParserUser,         new const Registration<T>)});
    route_map.insert({AUTHENTICATION,         NodeMap<T>(new const ParserUser,         new const Authentication<T>)});
    route_map.insert({ADD_EVENT,              NodeMap<T>(new const ParserEvent,        new const AddEvent<T>)});
    route_map.insert({RM_EVENT,               NodeMap<T>(new const ParserEvent,        new const RmEvent<T>)});
    route_map.insert({ADD_USER_GROUP,         NodeMap<T>(new const ParserUserContacts, new const AddUserContacts<T>)});
    route_map.insert({RM_USER_GROUP,          NodeMap<T>(new const ParserUserContacts, new const RmUserContacts<T>)});
    route_map.insert({ADD_GROUP,              NodeMap<T>(new const ParserGroup,        new const AddGroup<T>)});
    route_map.insert({ADD_USER_GROUP,         NodeMap<T>(new const ParserGroup,        new const AddUserGroup<T>)});
    route_map.insert({RM_USER_GROUP,          NodeMap<T>(new const ParserGroup,        new const RmUserGroup<T>)});
    route_map.insert({RM_GROUP,               NodeMap<T>(new const ParserGroup,        new const RmGroup<T>)});
    route_map.insert({GET_MEETUP,             NodeMap<T>(new const ParserMeetUp,       new const GetMeetUps<T>)});
}

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker, class ClassDBManager>
std::string RouteImpl<T, ClassConnection, ClassDBMethods, ClassDBWorker, ClassDBManager>::GetHeadRequest(const std::string &request_body) const {
    std::string type_request;

    return type_request;
}

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker, class ClassDBManager>
std::string RouteImpl<T, ClassConnection, ClassDBMethods, ClassDBWorker, ClassDBManager>::GetResTask(const std::string &request_body) {
    std::string type_request;

    return type_request;
}

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker, class ClassDBManager>
void RouteImpl<T, ClassConnection, ClassDBMethods, ClassDBWorker, ClassDBManager>::InsertTask(const std::string &task) {
}

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker, class ClassDBManager>
std::string RouteImpl<T, ClassConnection, ClassDBMethods, ClassDBWorker, ClassDBManager>::HandlingTask(const std::string &request_body, const ClassDBWorker &db_worker) const {
    std::string res;

    std::string type_request = GetHeadRequest(request_body);
    if (type_request.empty()) {
        return res;
    }

    auto needed_node = route_map.find(type_request);
    if (needed_node == route_map.end()) {
        return res;
    }

    Context buf;

    buf = needed_node->second.parser->StrToObject(request_body);
    buf = needed_node->second.handler->operator()(buf, db_worker);
    res = needed_node->second.parser->ObjectToStr(type_request, buf);

    return res;
}
