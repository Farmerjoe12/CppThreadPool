#include <thread>
#include <iostream>
#include <vector>

/** In this program we are using a vector to store a number of
 ** thread objects. These thread objects are all passed a function
 ** that will print a message to cout. Because of interleaving,
 ** the threads can be interrupted in their printing, and 
 ** cause results where cout is full of mixed messages
**/

void hello()
{
  // std::this_thread::get_id() returns the id of the 
  // thread being used to execute this message
  std:: cout << "Hello from thread " << std::this_thread::get_id() << std::endl;
}

int main()
{
  std::vector<std::thread> threads;
  
  for(int i = 0; i < 5; ++i)
  {
    // send the function to each thread
    threads.push_back(std::thread(hello));
  }

  // C++ generic for-each loop ;)
  for(auto& thread : threads)
  {
    // join threads before ending main
    thread.join();
  }

  return 0;
}
