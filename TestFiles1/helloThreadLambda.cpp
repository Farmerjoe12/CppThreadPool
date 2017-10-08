#include <thread>
#include <iostream>
#include <vector>

/** This program is essentially the same as helloThread2.cpp
 ** however, instead of a dedicated function call we are using
 ** a lambda expression for simplicity's sake
**/

int main()
{
  // create a vector of threads
  std::vector<std::thread> threads;

  for(int i = 0; i < 5; ++i)
  {
    // create our thread object and send the lambda function
    // at the same time
    threads.push_back(std::thread([](){
      std::cout << "Hello from thread" << std::this_thread::get_id()
<< std::endl;
    }));
  }

  for(auto& thread : threads)
  {
    thread.join();
  }

  return 0;
}
