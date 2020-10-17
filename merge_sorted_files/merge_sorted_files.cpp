#include "../std_lib_facilities.h"

/*
- takes two files containing sorted whitespace-separated words and merges them.
- the words in new file are also sorted.
*/

int main()
{
  ifstream ist1{"tmp1.txt"};
  ifstream ist2{"tmp2.txt"};
  ofstream ost{"tmp3.txt"};
  string w1;
  string w2;
  ist1 >> w1;
  ist2 >> w2;
  while (true)
  {
    if (ist1 && ist2)
    {
      if (w1 < w2)
      {
        ost << w1 << ' ';
        ist1 >> w1;
      }
      else
      {
        ost << w2 << ' ';
        ist2 >> w2;
      }
    }
    else if (ist1 && !ist2)
    {
      ost << w1 << ' ';
      ist1 >> w1;
    }
    else if (!ist1 && ist2)
    {
      ost << w2 << ' ';
      ist2 >> w2;
    }
    else
      break;
  }
}