#pragma once  //  NOLINT

#include <string>

class GeneralData {
    std::string user_id;
    std::string status;
    std::string tags;
    std::string description;
    std::string nickname;
public:
    bool IsEmpty();

    void SetUserId(const std::string &user_id);
    void SetStatus(const std::string &status);
    void SetTags(const std::string &tags);
    void SetDescription(const std::string &description);
    void SetNickname(const std::string &nickname);

    std::string SetUserId() const;
    std::string SetStatus() const;
    std::string SetTags() const;
    std::string SetDescription() const;
    std::string SetNickname() const;

    GeneralData() = default;
    virtual ~GeneralData() = default;

    void Print() const;
};


