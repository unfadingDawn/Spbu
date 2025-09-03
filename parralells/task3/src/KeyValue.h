#pragma once
#include <mutex>
#include <string>
namespace multithread_container {
    struct BaseValue {
        std::string text;
        int number;
        BaseValue(const std::string &text, const int val) : text(text), number(val) {}
        BaseValue() :number(0) {}

        bool operator==(const BaseValue & value) const {
            return text == value.text && number == value.number;
        }
    };
    struct Value {
        BaseValue value;
        int hash;
        Value(const BaseValue &value, const int hash) : value(value), hash(hash) {}
        Value() : value(), hash(0) {}

        bool operator==(const Value & value) const {
            return this->value == value.value && this->hash == value.hash;
        }
    };
    class List {
        private:
            std::mutex mutex;
            List* next;
            Value curr;
            List* prev;
            bool is_deleted_;
        public:
            List(List* n, const Value& c, List* p) : next(n), curr(c), prev(p), is_deleted_(false) {}
            List(const List& list) : next(list.next), curr(list.curr), prev(list.prev), is_deleted_(list.is_deleted_) {}
            List() : next(nullptr), curr(), prev(nullptr), is_deleted_(true) {}
            void add(const Value& v);
            void remove(int hash);
            int getHash();
            [[nodiscard]] List* getNext() const {return next;}
            [[nodiscard]] bool isEmpty();
    };
}
