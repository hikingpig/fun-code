#include "std_lib_facilities.h"
/*
- swap is defined in std
- we manipulate the vector directly without a intermediate storage
- the elements are swapped through the center of symmetry: v.size()/2
*/

void reverse(vector<int> &v)
{
  int num_of_swap = v.size()/2;
  int last_idx = v.size() -1;
  for (int i = 0; i < num_of_swap; ++i) {
    swap(v[i], v[last_idx -i]);
  }
}

int main() {
  vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
  reverse(v);
  for (int x: v) {
    cout << x << '\n';
  }
}
