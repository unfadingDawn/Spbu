#pragma once
#include <string>

namespace utils {
class Message {
private:
    std::string message;

public:
    explicit Message(std::string const& message) : message(message){};

    std::string to_string() const {
        return message;
    }
};
}  // namespace utils
