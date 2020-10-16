#include "Roman_num.h"

// check if a character is a valid roman numeral
bool is_roman(char c)
{
  return (c == 'i' || c == 'I' || c == 'v' || c == 'V' || c == 'x' || c == 'X' || c == 'l' || c == 'L' || c == 'c' || c == 'C' || c == 'm' || c == 'M');
}

// check if a string is a valid roman number
bool is_valid(string s)
{
  int repeated_i = 0;
  int repeated_v = 0;
  int repeated_x = 0;
  int repeated_l = 0;
  int repeated_c = 0;
  int repeated_d = 0;
  int repeated_m = 0;
  for (int i = 0; i < s.length(); ++i)
  {
    if (!is_roman(s[i]))
      return false;
    switch (s[i])
    {
    case 'i':
    case 'I':
      ++repeated_i;
      break;
    case 'v':
    case 'V':
      ++repeated_v;
      break;
    case 'x':
    case 'X':
      ++repeated_x;
      break;
    case 'l':
    case 'L':
      ++repeated_l;
      break;
    case 'c':
    case 'C':
      ++repeated_c;
      break;
    case 'd':
    case 'D':
      ++repeated_d;
      break;
    case 'm':
    case 'M':
      ++repeated_m;
      break;
    }
    if (repeated_i > 3 || repeated_v > 3 || repeated_x > 3 || repeated_l > 3 || repeated_c > 3 || repeated_d > 3 || repeated_m > 3)
      return false;
  }
  return true;
}

Roman_num::Roman_num(string r) : roman{r}
{
  if (!is_valid(r))
    error("Not a valid roman number");
}

// convert a roman character to integer
int char_to_int(char c)
{
  switch (c)
  {
  case 'i':
  case 'I':
    return 1;
  case 'v':
  case 'V':
    return 5;
  case 'x':
  case 'X':
    return 10;
  case 'l':
  case 'L':
    return 50;
  case 'c':
  case 'C':
    return 100;
  case 'd':
  case 'D':
    return 500;
  case 'm':
  case 'M':
    return 1000;
  default:
    error("Not a roman numerals");
  }
}

int Roman_num::as_int() const
{
  int val = 0;
  int i = 0;
  for (; i < roman.size() - 1; ++i)
    if (char_to_int(roman[i]) < char_to_int(roman[i + 1]))
      val -= char_to_int(roman[i]);
    else
      val += char_to_int(roman[i]);
  val += char_to_int(roman[i]); // the last character
  return val;
}

string digit_to_roman(int d, string one, string five, string ten)
{
  if (0 < d && d < 4)
  {
    string res;
    for (int i = 0; i < d; ++i)
      res += one;
    return res;
  }
  else if (d == 4)
    return one + five;
  else if (d == 5)
    return five;
  else if (5 < d && d < 9)
  {
    string res = five;
    for (int i = 0; i < d - 5; ++i)
      res += one;
    return res;
  }
  else if (d == 9)
    return one + ten;
  else
    error("Not a digit");
}

string digit_to_roman(int d, string one)
{
  if (0 < d && d < 4)
  {
    string res;
    for (int i = 0; i < d; ++i)
      res += one;
    return res;
  }
  else
    error("Not a digit between 1 and 3");
}

string int_to_roman(int n)
{
  if (n <= 0 || 4000 <= n)
    error("Can only handle positive number less than 4000");
  string res;
  int d;
  if (n >= 1000)
  {
    d = (n - n % 1000) / 1000;
    n -= d * 1000;
    res += digit_to_roman(d, "M");
  }
  if (n >= 100)
  {
    d = (n - n % 100) / 100;
    n -= d * 100;
    res += digit_to_roman(d, "C", "D", "M");
  }
  if (n >= 10)
  {
    d = (n - n % 10) / 10;
    n -= d * 10;
    res += digit_to_roman(d, "X", "L", "C");
  }
  if (n > 0)
    res += digit_to_roman(n, "I", "V", "X");
  return res;
}

Roman_num::Roman_num(int n)
{
  roman = int_to_roman(n);
}

ostream &operator<<(ostream &os, const Roman_num &r)
{
  return os << r.get();
}

istream &operator>>(istream &is, Roman_num &r)
{
  string s;
  char ch;

  // use get(ch) to read whitespaces
  // don't use noskipws. it creates a mess!
  while (is.get(ch) && is_roman(ch))
    s += ch;
  if (!isspace(ch))
    is.putback(ch);
  r = Roman_num(s);
  return is;
}

Roman_num operator+(const Roman_num &r1, const Roman_num &r2)
{
  return Roman_num(r1.as_int() + r2.as_int());
}

Roman_num operator-(const Roman_num &r1, const Roman_num &r2)
{
  return Roman_num(r1.as_int() - r2.as_int());
}

Roman_num operator*(const Roman_num &r1, const Roman_num &r2)
{
  return Roman_num(r1.as_int() * r2.as_int());
}

Roman_num operator/(const Roman_num &r1, const Roman_num &r2)
{
  return Roman_num(r1.as_int() / r2.as_int());
}