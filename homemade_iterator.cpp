#include "std_lib_facilities.h"

/*
- the class's vector data are not exposed
- to read these data, we use iterator
- the iterator doesn't change the state, it is a constant member of the class
- the iterator can be used in overloading operator such as << and ==
- each time `iterate` is called, we move to the next elements of the vectors
- iteration stop when the index exceeds the vector's size
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

bool operator==(const Name_pairs &np1, const Name_pairs &np2)
{
  int idx1 = 0;
  int idx2 = 0;
  string s1, s2;
  double a1, a2;
  np1.iterate(idx1, s1, a1);
  np2.iterate(idx2, s2, a2);
  while (idx1 > 0 && idx2 > 0)
  {
    if (!(s1 == s2 && a1 == a2))
      return false;
    np1.iterate(idx1, s1, a1);
    np2.iterate(idx2, s2, a2);
  }
  if (idx1 == idx2) // handle empty vector too
    return true;
  else // size of vectors are not the same
    return false;
}
int main()
{
  Name_pairs np;
  np.read_names();
  np.read_ages();
  cout << np;

  Name_pairs np2;
  np2.read_names();
  np2.read_ages();
  cout << np2;

  cout << (np == np2) << '\n';
}