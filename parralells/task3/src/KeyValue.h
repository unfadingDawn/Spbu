#pragma once
#include <mutex>
#include <string>

namespace multithread_container {
struct BaseValue {
    std::string text;
    int number;

    BaseValue(std::string const &text, int const val) : text(text), number(val) {}

    BaseValue() : number(0) {}

    bool operator==(BaseValue const &value) const {
        return text == value.text && number == value.number;
    }
};

struct Value {
    BaseValue value;
    int hash;

    Value(BaseValue const &value, int const hash) : value(value), hash(hash) {}

    Value() : value(), hash(0) {}

    bool operator==(Value const &value) const {
        return this->value == value.value && this->hash == value.hash;
    }
};

class List {
private:
    std::mutex mutex;
    List *next;
    Value curr;
    List *prev;
    bool is_deleted_;

public:
    List(List *n, Value const &c, List *p) : next(n), curr(c), prev(p), is_deleted_(false) {}

    List(List const &list)
        : next(list.next), curr(list.curr), prev(list.prev), is_deleted_(list.is_deleted_) {}

    List() : next(nullptr), curr(), prev(nullptr), is_deleted_(true) {}

    void add(Value const &v);
    void remove(int hash);
    int getHash();

    [[nodiscard]] List *getNext() const {
        return next;
    }

    [[nodiscard]] bool isEmpty();
};
}  // namespace multithread_container
