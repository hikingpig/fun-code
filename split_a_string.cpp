#include "std_lib_facilities.h"

// split a string into words. whitespaces are normal whitespaces and characters of w

bool is_char_of(char x, const string &s)
{
  for (char y : s)
    if (x == y)
      return true;
  return false;
}

vector<string> split(const string &s, const string &w)
{
  vector<string> res;
  string word;
  for (const char &x : s)
  {
    if (is_char_of(x, w) || isspace(x))
    {
      if (word != "")
        res.push_back(word);
      word = "";
      continue;
    }
    word += x;
  }
  char last = s[s.length() - 1];
  if (!(is_char_of(last, w) || isspace(last)))
    if (word != "")
      res.push_back(word);
  return res;
}

int main()
{
  string s = "a b c , d; e. f?klm-n -";
  string w = ",;?.-";
  vector<string> res = split(s, w);
  for (string x : res)
    cout << x << '\n';
}