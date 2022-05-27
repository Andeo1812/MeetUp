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

    std::string &GetUserId() noexcept;
    std::string &GetStatus() noexcept;
    std::string &GetTags() noexcept;
    std::string &GetDescription() noexcept;
    std::string &GetNickname() noexcept;

    const std::string &AccessUserId() const  noexcept;
    const std::string &AccessStatus() const  noexcept;
    const std::string &AccessTags() const  noexcept;
    const std::string &AccessDescription() const  noexcept;
    const std::string &AccessNickname() const  noexcept;

    GeneralData() = default;
    virtual ~GeneralData() = default;

    friend std::ostream&  operator<<(std::ostream &os, const GeneralData &it) noexcept;
};


