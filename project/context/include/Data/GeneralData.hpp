#pragma once  //  NOLINT

#include <string>

class GeneralData {
    std::string user_id;
    std::string status;
    std::string tags;
    std::string description;
    std::string nickname;

 public:
    bool IsEmpty() const noexcept;

    void SetUserId(const std::string &user_id) noexcept;
    void SetStatus(const std::string &status) noexcept;
    void SetTags(const std::string &tags) noexcept;
    void SetDescription(const std::string &description) noexcept;
    void SetNickname(const std::string &nickname) noexcept;

    std::string GetUserId() const noexcept;
    std::string GetStatus() const noexcept;
    std::string GetTags() const noexcept;
    std::string GetDescription() const noexcept;
    std::string GetNickname() const noexcept;

    GeneralData() = default;
    virtual ~GeneralData() = default;

    friend std::ostream&  operator<<(std::ostream &os, const GeneralData &it) noexcept;
};


