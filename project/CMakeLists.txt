INCLUDE_DIRECTORIES(context/include)

INCLUDE_DIRECTORIES(handling/include/impl)
INCLUDE_DIRECTORIES(handling/include/impl/Group)
INCLUDE_DIRECTORIES(handling/include/impl/Data)
INCLUDE_DIRECTORIES(handling/include/virtual)

INCLUDE_DIRECTORIES(route/include/impl)
INCLUDE_DIRECTORIES(route/include/virtual)

INCLUDE_DIRECTORIES(parsing/JSON/libs/single_include/nlohmann)
INCLUDE_DIRECTORIES(parsing/include/impl)
INCLUDE_DIRECTORIES(parsing/include/impl/Group)
INCLUDE_DIRECTORIES(parsing/include/impl/Data)
INCLUDE_DIRECTORIES(parsing/include/virtual)

INCLUDE_DIRECTORIES(database/PostgreSQL/include)
INCLUDE_DIRECTORIES(database/include/impl)

SET(SOURCE_LIST_SERVER
        main.cpp)

SET(SOURCE_LIST_ROUTE
        route/src/RouteImpl.cpp)

SET(SOURCE_LIST_PROCESSING_CLASS
        handling/src/HandlerContacts.cpp
        handling/src/HandlerEvent.cpp
        handling/src/Group/Base/HandlerGroup.cpp
        handling/src/Group/User/HandlerGroupManagement.cpp
        handling/src/Group/MeetUp/HandlerMeetUp.cpp
        handling/src/HandlerSynchroClient.cpp
        handling/src/HandlerRegiAuth.cpp
        handling/src/Data/HandlerAddressData.cpp
        handling/src/Data/HandlerGeneralData.cpp
        handling/src/Data/HandlerPrivateData.cpp
        handling/src/Data/HandlerPersonalData.cpp)

SET(SOURCE_LIST_PARSER_CLASS
        parsing/JSON/src/ParserContacts.cpp
        parsing/JSON/src/ParserEvent.cpp
        parsing/JSON/src/Group/ParserGroup.cpp
        parsing/JSON/src/Group/ParserMeetUp.cpp
        parsing/JSON/src/ParserRegAuth.cpp
        parsing/JSON/src/Data/ParserAddressData.cpp
        parsing/JSON/src/Data/ParserGeneralData.cpp
        parsing/JSON/src/Data/ParserPersonalData.cpp)

SET(SOURCE_LIST_PARSER_OBJECT
        context/src/Contacts.cpp
        context/src/AddressData.cpp
        context/src/Event.cpp
        context/src/GeneralData.cpp
        context/src/Group.cpp
        context/src/MeetUp.cpp
        context/src/PersonalData.cpp
        context/src/User.cpp)

SET(SOURCE_LIST_DATABASE
        database/PostgreSQL/src/GetID.cpp
        database/PostgreSQL/src/RegAuth.cpp
        database/PostgreSQL/src/Contact.cpp
        database/PostgreSQL/src/Event.cpp
        database/PostgreSQL/src/Data/Address.cpp
        database/PostgreSQL/src/Data/Personal.cpp
        database/PostgreSQL/src/Data/Security.cpp
        database/PostgreSQL/src/Data/General.cpp
        database/PostgreSQL/src/Group/Base.cpp
        database/PostgreSQL/src/Group/Management.cpp
        database/PostgreSQL/src/SynchronizationClient.cpp
        database/PostgreSQL/src/PGConnection.cpp)


ADD_EXECUTABLE(${PROJECT_NAME}
        ${SOURCE_LIST_SERVER}
        ${SOURCE_LIST_ROUTE}
        ${SOURCE_LIST_PROCESSING_CLASS}
        ${SOURCE_LIST_PARSER_CLASS}
        ${SOURCE_LIST_PARSER_OBJECT}
        ${SOURCE_LIST_DATABASE})

