#include <iostream>
#include <thread>
#include <vector>

/** This program clearly demonstrates the issue with threading 
 ** and interleaving. Where interleaving in this case is
 ** the process of multiple threads executing some statements
 ** at the same time. To prevent this, some locks are required
 ** on the cout file.
**/

// Counter is a simple struct that has a single value and 
//  a function to increment that value
struct Counter {
  int value;
 
  Counter() : value(0){}

  void increment() {
    ++value;
  }
};

// What we see happening in main is the same creation of a thread
//  vector and passing a function at creation time. However
//  since the counter is not locked by a thread, any thread can
//  access and mutate the variable at any time, causing values 
//  to be mixed up and false results to be returned.
// Ideally, main will return 500, but due to interleaving, there
//  is no way to predict the result of execution.

int main() {
  Counter counter;

  std::vector<std::thread> threads;

  // 5 threads incrementing the counter var in Counter 100x

  /** NOTE: I changed the number of threads to 2 in order
   ** For my dual core machine to properly execute this code
   ** and produce an interleaved effect as intended. Your 
   ** mileage may vary.
  **/
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
