#include <iostream>
#include <thread>
#include <vector>

#include "program.h"
#include "util.h"
std::mutex mutex;
std::vector<int> nums = {1, 2, 4, 5, 3, 6, 7, 8, 6, 4};

void make_sum(std::vector<int>& indexes) {
   // std::lock_guard<std::mutex> guard(mutex);
   int sum = 0;
   for (const auto& index : indexes) {
      sum += nums[index];
   }
   for (const auto& index : indexes) {
      nums[index] = sum;
   }
}

int main() {
   int size = nums.size();
   std::vector<int> indexes1 = util::rand_indexes(size);
   std::vector<int> indexes2 = util::rand_indexes(size);
   std::thread t1(make_sum, std::ref(indexes1));
   std::thread t2(make_sum, std::ref(indexes2));
   t1.join();
   t2.join();
   for (const auto& num : nums ) {
      std::cout << num << ' ';
   }
   std::cout << std::endl;
   return 0;
}