#pragma once
#include <string>
namespace utils {
    class Message {
    private:
        std::string message;
    public:
        explicit Message(const std::string& message): message(message) {};
        std::string to_string() const {
            return message;
        }
    };
}
