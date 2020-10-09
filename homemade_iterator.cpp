#include "std_lib_facilities.h"

/*
- iterate function is a constant member of the class
- the iteration index is passed from outside
- iteration will stop when the iteration index exceeds vector's size.
- the condition to stop iterating is the iteration idex < 0. we deliberately set it at the end of iteration
*/

const string quit = "NoName";

class Name_pairs
{
public:
  void read_names();
  void read_ages();
  void my_sort();
  void iterate(int &idx, string &n, double &a) const;

private:
  vector<string> names;
  vector<double> ages;
};

void Name_pairs::read_names()
{
  cout << "Enter the series of names. Type " << quit << " to quit\n";
  string name;
  while (true)
  {
    cin >> name;
    if (name == quit)
      break;
    names.push_back(name);
  }
}

void Name_pairs::read_ages()
{
  double age;
  for (string n : names)
  {
    cout << "Enter age for " << n << ": ";
    cin >> age;
    ages.push_back(age);
  }
}

void Name_pairs::my_sort()
{
  vector<string> names_tmp = names;
  sort(names);
  vector<double> ages_tmp;
  for (string n : names)
  {
    for (int i = 0; i < names_tmp.size(); ++i)
    {
      if (n == names_tmp[i])
      {
        ages_tmp.push_back(ages[i]);
        break;
      }
    }
  }
  ages = ages_tmp;
}

void Name_pairs::iterate(int &idx, string &n, double &a) const
{
  if (idx < 0 || idx >= names.size())
  {
    idx = -1;
    return;
  }
  n = names[idx];
  a = ages[idx];
  ++idx;
}

ostream &operator<<(ostream &os, const Name_pairs &np)
{
  os << "-------------------------------------------\n";
  string name;
  double age;
  int idx = 0;
  np.iterate(idx, name, age);
  while (idx > 0)
  {
    os << name << '\t' << age << '\n';
    np.iterate(idx, name, age);
  }
  return os;
}

int main()
{
  Name_pairs np;
  np.read_names();
  np.read_ages();
  np.my_sort();
  cout << np;
}