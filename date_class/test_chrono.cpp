#include "chrono.h"
// compile with `g++ test_chrono.cpp chrono.cpp compute_date.cpp date_types.cpp`
void test_set_days()
{
  //Wednesday 21 january 1970
  Chrono::Date date{20};
  cout << date << '\n';

  // Saturday 31 January 1970

  date.set_days(30);
  cout << date << '\n';

  // Sun 1 Feb 1970
  date.set_days(31);
  cout << date << '\n';

  // Mon 9 Feb 1970
  date.set_days(39);
  cout << date << '\n';

  // Sat 28 Feb 1970
  date.set_days(58);
  cout << date << '\n';

  // Sun 1 Mar 1970
  date.set_days(59);
  cout << date << '\n';

  // Sun 15 March 1970
  date.set_days(73);
  cout << date << '\n';

  // Wed 15 Apr 1970
  date.set_days(104);
  cout << date << '\n';
}

void test_add_year()
{
  Chrono::Date date{788};
  cout << date << '\n';
  // Feb 28 will be the same, no matter how much year we add!
  date.add_year(1);
  cout << date << '\n';

  date.add_year(1);
  cout << date << '\n';

  date.add_year(1);
  cout << date << '\n';

  date.add_year(1);
  cout << date << '\n';

  // Feb 29 will only the same if we add 4x years. It will be 1 March otherwise
  date.add_day(1);
  cout << date << '\n';

  date.add_year(4);
  cout << date << '\n';
  date.add_year(16);
  cout << date << '\n';

  // Feb 29 is now 1 Mar. 1 Mar will be the same no matter how many years we add
  date.add_year(1);
  cout << date << '\n';

  date.add_year(1);
  cout << date << '\n';

  date.add_year(1);
  cout << date << '\n';

  date.add_year(1);
  cout << date << '\n';
}

void test_add_month()
{
  Chrono::Date date{11};
  cout << date << '\n';

  date.add_month(1);
  cout << date << '\n';
  cout << "--------------------\n";

  date.set_days(30);
  cout << date << '\n';

  date.add_month(1);
  cout << date << '\n';
  cout << "--------------------\n";

  date.set_days(30);
  cout << date << '\n';

  date.add_month(4);
  cout << date << '\n';

  date.add_month(0);
  cout << date << '\n';
  cout << "--------------------\n";

  date.set_days(30);
  cout << date << '\n';

  date.add_month(5);
  cout << date << '\n';
  cout << "--------------------\n";

  date.set_days(30);
  cout << date << '\n';

  date.add_month(6);
  cout << date << '\n';
  cout << "--------------------\n";

  date.set_days(30);
  cout << date << '\n';

  date.add_month(7);
  cout << date << '\n';
  cout << "--------------------\n";

  date.set_days(30);
  cout << date << '\n';

  date.add_month(8);
  cout << date << '\n';
  cout << "--------------------\n";

  date.set_days(30);
  cout << date << '\n';

  date.add_month(9);
  cout << date << '\n';
  cout << "--------------------\n";

  date.set_days(30);
  cout << date << '\n';

  date.add_month(10);
  cout << date << '\n';
  cout << "--------------------\n";

  date.set_days(30);
  cout << date << '\n';

  date.add_month(11);
  cout << date << '\n';
  cout << "--------------------\n";

  date.set_days(360);
  cout << date << '\n';

  date.add_month(1);
  cout << date << '\n';
  cout << "--------------------\n";

  date.set_days(360);
  cout << date << '\n';

  date.add_month(2);
  cout << date << '\n';
  cout << "--------------------\n";

  date.set_days(89);
  cout << date << '\n';

  date.add_month(11);
  cout << date << '\n';
  cout << "--------------------\n";

  date.set_days(89);
  cout << date << '\n';

  date.add_month(10);
  cout << date << '\n';
  cout << "--------------------\n";

  date.set_days(89);
  cout << date << '\n';

  date.add_month(48);
  cout << date << '\n';
  cout << "--------------------\n";
  date.set_days(58);
  cout << date << '\n';

  date.add_year(2);
  date.add_day(1);
  cout << date << '\n';

  date.add_month(48);
  cout << date << '\n';
  cout << "--------------------\n";
}

void test_input()
{
  Chrono::Date d{0};
  cout << "enter a year in the form (yyyy, mm, dd) \n";
  cin >> d;

  cout << d << '\n';
}
int main()
{
  cout << "====================== Test Set Days ========================\n";
  test_set_days();
  cout << "====================== Test Year ========================\n";
  test_add_year();

  cout << "====================== Test Month ========================\n";
  test_add_month();

  cout << "====================== Test Input ========================\n";
  test_input();
}