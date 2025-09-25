#include "KeyValue.h"

#include <memory>

namespace multithread_container {
void List::add(Value const &v) {
    if (isEmpty()) {
        std::lock_guard lock(mutex);
        curr = v;
        is_deleted_ = false;
        return;
    }
    List *prev_temp;
    List *temp;
    mutex.lock();
    if (next != nullptr) {
        temp = next;
        prev_temp = temp->prev;
    } else {
        temp = nullptr;
        prev_temp = this;
    }
    mutex.unlock();
    if (temp != nullptr) {
        while (temp != nullptr) {
            prev_temp = prev_temp->next;
            temp = temp->next;
        }
    }
    std::lock_guard lock(prev_temp->mutex);
    prev_temp->next = new List(nullptr, v, prev_temp);
}

void List::remove(int const hash) {
    List const *temp = prev;
    List *next_temp;
    if (temp != nullptr) {
        next_temp = temp->next;
    } else {
        next_temp = this;
    }
    while (temp != nullptr) {
        temp = temp->prev;
        next_temp = next_temp->prev;
    }
    while (next_temp->curr.hash != hash) {
        next_temp = next_temp->next;
        if (next_temp == nullptr) {
            return;
        }
    }
    next_temp->mutex.lock();
    if (next_temp->prev != nullptr) {
        next_temp->mutex.unlock();
        next_temp->prev->mutex.lock();
    } else {
        next_temp->mutex.unlock();
    }
    next_temp->mutex.lock();
    if (next_temp->next != nullptr) {
        next_temp->next->mutex.lock();
    }
    if (next_temp->prev == nullptr && next_temp->next == nullptr) {
        next_temp->is_deleted_ = true;
        next_temp->mutex.unlock();
        return;
    }
    if (next_temp->prev != nullptr) {
        next_temp->prev->next = next_temp->next;
        next_temp->prev->mutex.unlock();
        next_temp->prev = nullptr;
    }
    if (next_temp->next != nullptr) {
        next_temp->next->prev = next_temp->prev;
        next_temp->next->mutex.unlock();
        next_temp->next = nullptr;
    }
    next_temp->is_deleted_ = true;
    next_temp->mutex.unlock();
}

int List::getHash() {
    std::lock_guard lock(mutex);
    return curr.hash;
}

bool List::isEmpty() {
    std::lock_guard lock(mutex);
    return prev == nullptr && is_deleted_ && next == nullptr;
}
}  // namespace multithread_container
