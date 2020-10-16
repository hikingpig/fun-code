#include "../std_lib_facilities.h"

class Roman_num
{
public:
  int as_int() const;
  Roman_num(string r);
  Roman_num(int n);
  string get() const { return roman; };

private:
  string roman;
};

ostream &operator<<(ostream &os, const Roman_num &r);

istream &operator>>(istream &is, Roman_num &r);

Roman_num operator+(const Roman_num &r1, const Roman_num &r2);
Roman_num operator-(const Roman_num &r1, const Roman_num &r2);
Roman_num operator*(const Roman_num &r1, const Roman_num &r2);
Roman_num operator/(const Roman_num &r1, const Roman_num &r2);