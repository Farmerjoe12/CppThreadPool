#include <thread>
#include <iostream>

/** For some reason, on my laptop this file requires the use
 ** of -pthread in the compile arguments before -std=c++11
**/

void hello()
{
  // Simple function, print a message from a thread
  std::cout << "Hello from thread" << std::endl;
}

int main()
{
  // Create a thread using a constructor that takes a function ref
  std::thread t1(hello);

  // waiting to join t1 before ending main to prevent crash
  t1.join();
  return 0;
}
