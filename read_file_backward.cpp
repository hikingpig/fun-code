#include "std_lib_facilities.h"

/*
There is no really good, portable, and efficient way of reading a file backward
*/

int main()
{
  cout << "please enter input file name: ";
  string iname;
  cin >> iname;
  ifstream is{iname};
  if (!is)
    error("Failed to open ", iname);
  cout << "please enter output filename: ";
  string oname;
  cin >> oname;
  ofstream os{oname};
  if (!os)
    error("Failed to open ", oname);
  int i = 0;
  while (is)
  {
    // cout also for whitespaces
    is.get();
    ++i;
  }
  i -= 2;

  if (i < 0)
    error("Empty file");

  is.clear();

  char c;
  while (i >= 0)
  {
    is.seekg(i);
    // include whitespaces
    c = is.get();
    os << c;
    --i;
  }
}