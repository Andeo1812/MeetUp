#pragma once  //  NOLINT

#include <string>

class User {
    std::string user_id;
    std::string password;
    std::string nickname;
public:
    bool IsEmpty();

    void SetUserId(const std::string &user_id);
    void SetPassword(const std::string &password);
    void SetNickname(const std::string &nickname);

    std::string GetUserId() const;
    std::string GetPassword() const;
    std::string GetNickname() const;

    User() = default;
    virtual ~User() = default;

    void Print() const;
};
