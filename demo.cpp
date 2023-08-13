#include <chrono>
#include <iostream>
#include <thread>

#include "timer.hpp"

void long_function() {
  std::cout << "I will now sleep for 1 second" << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << "done!" << std::endl;
}

int main() {

  timer::Timer timer_("myTimer");

  long_function();

  // you can ask for the time in a specific format
  std::cout << "seconds: " << timer_.elapsed<std::chrono::seconds>()
            << std::endl;

  // use the built in micro/milliseconds:
  std::cout << "milliseconds: " << timer_.elapsed_ms() << std::endl;

  std::cout << "log: " << timer_.log() << std::endl;

  timer_.print("1");
  timer_.print("2");
  timer_.print("3");

  // or on destruction of the object it will automatically print the time taken
  // to the console.

  std::cout << std::endl;
}
