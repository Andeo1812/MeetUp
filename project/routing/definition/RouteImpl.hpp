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
RouteImpl::RouteImpl() {
    //  Base            REQUEST                                        PARSER                     HANDLER
    route_map.insert({REGISTRATION,           Node(new ParserUser,         new Registration)});
    route_map.insert({AUTHENTICATION,         Node(new ParserUser,         new Authentication)});
    route_map.insert({ADD_EVENT,              Node(new ParserEvent,        new AddEvent)});
    route_map.insert({RM_EVENT,               Node(new ParserEvent,        new RmEvent)});
    route_map.insert({ADD_USER_GROUP,         Node(new ParserUserContacts, new AddUserContacts)});
    route_map.insert({RM_USER_GROUP,          Node(new ParserUserContacts, new RmUserContacts)});
    route_map.insert({ADD_GROUP,              Node(new ParserGroup,        new AddGroup)});
    route_map.insert({ADD_USER_GROUP,         Node(new ParserGroup,        new AddUserGroup)});
    route_map.insert({RM_USER_GROUP,          Node(new ParserGroup,        new RmUserGroup)});
    route_map.insert({RM_GROUP,               Node(new ParserGroup,        new RmGroup)});
    route_map.insert({GET_MEETUP,             Node(new ParserMeetUp,       new GetMeetUps)});
}

std::string RouteImpl::get_head(const std::string request_body) {
    std::string type_request;

    return type_request;
}

std::string RouteImpl::get_response(const std::string request_body) {
    std::string res;

    std::string type_request = get_head(request_body);
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
