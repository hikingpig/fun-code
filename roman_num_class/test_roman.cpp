#include "Roman_num.h"

int main()
{
  Roman_num a{"xiv"};
  cout << a.as_int() << '\n';

  ifstream ist{"data.txt"};
  if (!ist)
    error("Unable to open file ", "data.txt");

  ist.exceptions(ist.exceptions() | ios_base::badbit);

  Roman_num b{"iv"};
  for (Roman_num r{"i"}; ist >> r;)
    cout << r << '\n';
  
  cout << a + b << '\n';
  cout << a - b << '\n';
  cout << a * b << '\n';
  cout << a / b << '\n';
}