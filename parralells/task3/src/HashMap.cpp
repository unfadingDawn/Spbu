#include "HashMap.h"

namespace multithread_container {
void HashMap::put(HashMap &map, int const hash, BaseValue const &value) {
    map.buckets_[map.hash_func(hash)].add(Value(value, hash));
}

void HashMap::remove(HashMap &map, int const hash) {
    map.buckets_[map.hash_func(hash)].remove(hash);
}

bool HashMap::check(HashMap &map, int const hash) {
    auto temp = &map.buckets_[map.hash_func(hash)];
    while (temp != nullptr) {
        if (temp->getHash() != hash) {
            temp = temp->getNext();
        } else {
            return true;
        }
    }
    return false;
}
}  // namespace multithread_container
