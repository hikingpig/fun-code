#include "std_lib_facilities.h"
/*
- use only one bool vector to implement the eratosthenes sieve to find prime numbers
*/
int main()
{
  vector<bool> keep_pos;
  // the first prime is 2. 0, 1 must be discarded at initialization
  for (int i = 0; i < 2; ++i) {
    keep_pos.push_back(false);
  }
  for (int i = 2; i < 100; ++i)
  {
    keep_pos.push_back(true);
  }

  for (int i = 0; i < keep_pos.size(); ++i)
    if (keep_pos.at(i))
      for (int j = i + i; j < keep_pos.size(); j += i)
        keep_pos.at(j) = false;

  cout << "The prime numbers between 0 and 100 are:\n";
  int total = 0;
  for (int i = 0; i < keep_pos.size(); ++i)
    if (keep_pos.at(i))
    {
      ++total;
      cout << i << '\n';
    }
  cout << "Total: " << total << '\n';
}