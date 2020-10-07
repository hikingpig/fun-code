#include "std_lib_facilities.h"

/* 
- user input the number of primes they wanted
- the search range will be extended until the needed primes are found
- when search range is extended, we start sieving in the extended part, the search is not repeated in sieved range.
*/

bool enough_prime(int needed, vector<bool> k)
{
  int found = 0;
  for (int i = 0; i < k.size(); ++i)
    if (k.at(i))
    {
      ++found;
      if (found >= needed)
        return true;
    }
  return false;
}

vector<bool> erasthostenes_sieve(int start, int needed, vector<bool> k)
{
  int found = 0; 
  for (int i = 0; i < k.size(); ++i)
  {
    if (k.at(i))
    {
      ++found;
      if (needed <= found) // if found primes exceeded needed primes, stop searching
      {
        cout << "\u237E\u237E\u237E\u237E\u237E Enough Primes. DONE! Throw me a party boss!\n";
        return k;
      }
      if (start < i)
        start = i; // if 'start' is behind sieved value, use the step value.
      int s = (start / i + 1) * i;
      for (int j = s; j < k.size(); j += i)
        k.at(j) = false;
    }
  }
  return k;
}

int main()
{
  cout << "Please enter the number of primes you need\n";
  int needed = 0;
  cin >> needed;
  if (needed < 1)
  {
    cout << "Wrong input: " << needed << " .Exit now\n";
    return 1;
  }
  int start = 2;
  int end = 100;
  vector<bool> k;

  // discard 0 and 1 at initialization
  for (int i = 0; i < start; ++i)
  {
    k.push_back(false);
  }

  bool enough = false;

  // searching primes
  while (!enough)
  {
    cout << "Searching in (" << start << ", " << end << ")..." << '\n';
    for (int i = start; i < end; ++i)
    {
      k.push_back(true);
    }
    k = erasthostenes_sieve(start - 1, needed, k); // include 'start' value in search range
    enough = enough_prime(needed, k);
    start = end;
    end = 2 * end;
  }

  // print out the result
  cout << "The first " << needed << " primes are:\n";
  int total = 0;
  for (int i = 0; i < k.size(); ++i)
    if (k.at(i))
    {
      ++total;
      cout << i << '\n';
      if (total >= needed)
        break;
    }
}