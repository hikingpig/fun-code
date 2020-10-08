#include "std_lib_facilities.h"

/*
- user think of a number between 1 and 100. the program will guess it in less than 7 times
- the program asks just 1 question each time
- the program changes min and max until they are equal
- test cases: 1, 100, 2, 99, 33, 60, 49, 50
*/
int main()
{
  int min = 1;
  int max = 100;
  int mid = 0;
  char ans = 'y';
  cout << "Choose a number between 1 and 100. I will guess it in maximum 7 times\n";
  while (min < max)
  {
    cout << "min =" << min << "; max =" << max << '\n';
    mid = (max + min) / 2;
    cout << "Is your number smaller than or equal " << mid << "? (y/n)\n";
    cin >> ans;
    if (ans == 'y')
      max = mid;
    else
      min = mid + 1;
  }
  cout << "Your number is " << max << '\n';
}