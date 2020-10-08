#include "std_lib_facilities.h"

/*
- find the largest fibonacci number that can be stored in an integer
*/

int main()
{
  int fib1 = 0;
  int fib2 = 1;
  int fib3 = fib1 + fib2;
  cout << "N\tV\n";
  int n = 3;
  while (fib2 <= fib3) // overflow will terminate the loop
  {
    fib1 = fib2;
    fib2 = fib3;
    fib3 = fib1 + fib2;
    ++n;
    cout << n << '\t' << fib3 << '\n';
  }
}