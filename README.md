# Timer
super simple  header-only c++ timer that you can add to any project.

## Demo
clone this repo, and run
```
g++ -o demo demo.cpp
./demo
``` 

## Simple Usage
Just add `timer.hpp` to a include location. 
Requires `C++17`.

To time a code block, create the timer:
```
{ 
    timer::Timer myTimer();
    // 
    // lots of code
    // 
}
```

This will print the timing when `myTimer` goes out of scope. 
It uses `std::chrono::high_resolution_clock` for the timing.

## More Features

You can set some optional parameters when constructing `myTimer`
```
std::string name = "myTimer"; // default is "timer"
bool print_on_exit = false ;  // default is true
timer::Timer myTimer(name, print_on_exit)
```
If `print_on_exit` is true, the time taken will be printed to `std::cout` when `myTimer` is deleted. 

To get the time at a specific point in your code, 
```
uint64_t ms = myTimer.elapsed_ms() // to get the duration in milliseconds
uint64_t us = myTimer.elapsed_us() // to get the duration in microseconds
uint64_t mins = myTimer.elapsed<std::chrono::minutes>(); // to get the duration in any std::chrono::duration
```

You can also:
```
myTimer.reset()       // to reset the start time
myTimer.print()       // to print the current timing
myTimer.print(label)  // to print the current timing with a label.
```
