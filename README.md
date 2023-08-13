# Timer
super simple  header-only c++ timer that you can add to any project.


## Usage
Just add `timer.hpp` to a include location. 
Requires `C++17`.

To time a code block, create the timer:
```
timer::Timer myTimer();
```
or
```
std::string name = "myTimer"; // default is "timer"
bool print_on_exit = false ;  // default is true
timer::Timer myTimer(name, print_on_exit)
```
If `print_on_exit` is true, the time taken will be printed to `std::cout` when `myTimer` is deleted. 

You can also:
```
uint64_t ms = myTimer.elapsed_ms() // to get the duration in milliseconds
uint64_t us = myTimer.elapsed_us() // to get the duration in microseconds
uint64_t mins = myTimer.elapsed<std::chrono::minutes>(); // to get the duration in any std::chrono::duration

myTimer.reset() // to reset the start time
myTimer.print() // to print the current timing
myTimer.print(label) // to print the current timing with a label.
```
