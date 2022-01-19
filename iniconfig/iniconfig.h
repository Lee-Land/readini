//
// Created by xiamingjie on 2022/1/18.
//

#ifndef _INI_CONFIG_H
#define _INI_CONFIG_H

#include <fstream>
#include <string>
#include <exception>
#include <unordered_map>

namespace Ini {

    class ErrorLog : public std::exception {
    public:
        explicit ErrorLog(const std::string &format, ...);

        explicit ErrorLog(const char *format, ...);

        const char *what() const noexcept override;

    private:
        char message_[1024];
    };

    /**
     * 有限状态机解析状态
     * */
    enum class IniState {
        NOTHING,
        SECTION,
        PARAMETERS,
        COMMENTS,
        SECTION_ERROR,
        PARAMETERS_ERROR,
        SUCCESS
    };

    using Parameters = std::unordered_map<std::string, std::string>;
    using Section = std::unordered_map<std::string, Parameters>;

    class IniConfig {
    public:
        IniConfig();

        ~IniConfig() = default;

        void parse(std::istream &input) noexcept(false);

        size_t size() const;

        Parameters &operator[](const std::string &section_key);

        Parameters &operator[](int index) noexcept(false);

    private:
        Section sections_;
        IniState state_;
    };
}


#endif //_INI_CONFIG_H
