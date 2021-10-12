# for_constexpr
Compile-time loop that invokes given lambda or callable parameter N times

## Usage
```C++
#include <iostream>
#include <for_constexpr>

int main()
{
  stdx::for_constexpr<100>([]{ std::cout << "Hello!" << std::endl; }); // print "Hello!" 100 times 
}
```
