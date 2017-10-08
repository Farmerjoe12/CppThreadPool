#include <iostream>
#include <thread>

/** Code here comes from a C++11 tutorial on bogotobogo.com
**/

void thread_function()
{
  std::cout << "thread function\n";
}

int main()
{
  std::thread t(&thread_function);	// t begins execution of the function
  std::cout << "Number of threads = " 	// Querying thread count while t works
 	    << std::thread::hardware_concurrency() << std::endl;
  std::cout << "main thread\n";
  t.join();				// main waits for t to complete
  return 0;
}
