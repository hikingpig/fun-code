#include "../std_lib_facilities.h"

/*
- takes two files containing sorted whitespace-separated words and merges them.
- the words in new file are also sorted.
*/

int main()
{
  // setup file streams
  ifstream ist1{"tmp1.txt"};
  if (!ist1)
    error("Unable to open input file ", "tmp1.txt");
  ist1.exceptions(ist1.exceptions() | ios_base::badbit);

  ifstream ist2{"tmp2.txt"};
  if (!ist2)
    error("Unable to open input file ", "tmp2.txt");
  ist2.exceptions(ist2.exceptions() | ios_base::badbit);

  ofstream ost{"tmp3.txt"};
  if (!ost)
    error("Unable to open output file ", "tmp3.txt");
  ost.exceptions(ost.exceptions() | ios_base::badbit);
  // end setup file streams

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