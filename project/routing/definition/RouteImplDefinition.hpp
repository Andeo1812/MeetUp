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

template<class ClassDBManager>
RouteImpl<ClassDBManager>::RouteImpl() {
    //  Base            REQUEST                                        PARSER                     HANDLER
    route_map.insert({REGISTRATION,           NodeMap(new const ParserUser,         new const Registration)});
    route_map.insert({AUTHENTICATION,         NodeMap(new const ParserUser,         new const Authentication)});
    route_map.insert({ADD_EVENT,              NodeMap(new const ParserEvent,        new const AddEvent)});
    route_map.insert({RM_EVENT,               NodeMap(new const ParserEvent,        new const RmEvent)});
    route_map.insert({ADD_USER_GROUP,         NodeMap(new const ParserUserContacts, new const AddUserContacts)});
    route_map.insert({RM_USER_GROUP,          NodeMap(new const ParserUserContacts, new const RmUserContacts)});
    route_map.insert({ADD_GROUP,              NodeMap(new const ParserGroup,        new const AddGroup)});
    route_map.insert({ADD_USER_GROUP,         NodeMap(new const ParserGroup,        new const AddUserGroup)});
    route_map.insert({RM_USER_GROUP,          NodeMap(new const ParserGroup,        new const RmUserGroup)});
    route_map.insert({RM_GROUP,               NodeMap(new const ParserGroup,        new const RmGroup)});
    route_map.insert({GET_MEETUP,             NodeMap(new const ParserMeetUp,       new const GetMeetUps)});
}

template<class ClassDBManager>
std::string RouteImpl<ClassDBManager>::GetHeadRequest(const std::string &request_body) const {
    std::string type_request;

    return type_request;
}

template<class ClassDBManager>
std::string RouteImpl<ClassDBManager>::GetResTask(const std::string &request_body) {
    std::string type_request;

    return type_request;
}

template<class ClassDBManager>
void RouteImpl<ClassDBManager>::InsertTask(const std::string &task) {
}

template<class ClassDBManager>
std::string RouteImpl<ClassDBManager>::HandlingTask(const std::string &request_body) const {
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
    buf = needed_node->second.handler->process(buf);
    res = needed_node->second.parser->ObjectToStr(type_request, buf);

    return res;
}
