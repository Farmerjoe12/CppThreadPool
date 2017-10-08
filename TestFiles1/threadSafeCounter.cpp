#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

struct Counter {
  std::mutex mutex;
  int value;

  Counter() : value(0) {}

  void increment() {
    // With a lock guard, unlock and lock are automatically 
    // called and will handle all errors that could possibly 
    // arise.
    std::lock_guard<std::mutex> guard(mutex);
    ++value;
  }

  
};

// Here is the same main() from the unsyncronized thread counter
// Basically, we expect that we would produce an interleaving 
// effect here, but since we have the mutex lock on the value
// in struct Counter, we will always get a clean result
int main() {
  Counter counter;

  std::vector<std::thread> threads;

  for(int i = 0; i < 2; ++i) {
    threads.push_back(std::thread([&counter](){
      for(int i = 0; i < 100; ++i) {
        counter.increment();
      }
    }));
  }
 
  for(auto& thread : threads) {
    thread.join();
  }

  std::cout << counter.value << std::endl;

  return 0;
}
