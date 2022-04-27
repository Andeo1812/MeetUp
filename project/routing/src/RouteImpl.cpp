#include "RouteImpl.hpp"

#include "RouteMapKeys.hpp"

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

RouteImpl::RouteImpl() {
    //  Base            REQUEST                                        PARSER                     HANDLER
    route_map.insert({REGISTRATION,           std::make_pair(new ParserRegAuth,        new Registration)});
    route_map.insert({AUTHENTICATION,         std::make_pair(new ParserRegAuth,        new Authentication)});
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

    buf = needed_node->second.first->StrToObject(request_body);
    buf = needed_node->second.second->process(buf);
    res = needed_node->second.first->ObjectToStr(type_request, buf);

    return res;
}
