#include "std_lib_facilities.h"
/*
- sort 3 integers, as quick as possible
*/
int main() {
  cout << "Please enter 3 integers\n";
  int a, b, c;
  cin >> a >> b >> c;
  int min, mid, max;
  if (a < b) {
    min = a;
    max = b;
  } else {
    min = b;
    max = a;
  };
  if (c < min) {
    mid = min;
    min = c;
  } else if (c > max) {
    mid = max;
    max = c;
  } else {
    mid = c;
  };
  cout << "the numbers in order are: " << min << ' ' << mid << ' ' << max << '\n';
}