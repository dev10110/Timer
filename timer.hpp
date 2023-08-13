#pragma once

#include <chrono>
#include <iostream>

namespace timer {

class Timer {

  typedef std::chrono::high_resolution_clock clock;
  typedef std::chrono::milliseconds milliseconds;
  typedef std::chrono::microseconds microseconds;

public:
  Timer(std::string name = "timer", bool print_on_exit = true)
      : _name(name), _print_on_exit(print_on_exit) {
    reset();
  }

  ~Timer() {
    if (_print_on_exit)
      print();
  }

  void reset() { _start = clock::now(); }

  template <typename T> uint64_t elapsed() {
    auto dt = std::chrono::duration_cast<T>(clock::now() - _start);
    return dt.count();
  }

  uint64_t elapsed_ms() { return elapsed<milliseconds>(); }

  uint64_t elapsed_us() { return elapsed<microseconds>(); }

  void print(std::string label = "") {
    auto us = elapsed_us();
    auto ms = elapsed_ms();

    std::cout << "[ " << _name << " ] ";
    if (label != "") {
      std::cout << "[ " << label << " ] ";
    }

    std::cout << us << " us (" << ms << " ms)" << std::endl;
  }

private:
  clock::time_point _start;
  bool _print_on_exit = true;
  std::string _name;
};

} // namespace timer
