#include<thread>
#include<iostream>
#include<mutex>
#include<vector>
#include<chrono>

// This simple function will print a message to cout, sleep, then 
//  print another message. A mutex is used to lock cout so that only
//  one thread prints at a time.
void func() {
  std::mutex mutex;

  // Set a duration of wait time
  std::chrono::milliseconds duration(1000);

  // Lock the output stream
  mutex.lock();
  std::cout << "Hello from thread: " << std::this_thread::get_id()
    << ", starting sleep." << std::endl;
  mutex.unlock();

  // Put the thrad to sleep
  std::this_thread::sleep_for( duration );

  // Lock and print again
  mutex.lock();
  std::cout << "Sleep over, job complete. From thread: " 
    << std::this_thread::get_id() << std::endl;
  mutex.unlock();
}

int main() {
  // Get the number of cores from the machine
  int n = std::thread::hardware_concurrency();

  // Print the number of cores
  std::cout << "Number of usable threads: " << n << std::endl;

  // Create a vector of thread objects
  std::vector<std::thread> threads;

  // Print beginning of execution
  std::cout << "Beginning threading..." << std::endl;

  // Create our threads and call func()
  for(int i = 0; i < n; ++i) {
    threads.push_back(std::thread(func));
  }
  
  // Join each thread
  for(auto& thread: threads)
    thread.join();

  // Main done
  std::cout << "Main has finished..." << std::endl;
  return 0;
}
  
