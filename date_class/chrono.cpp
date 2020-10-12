#include "chrono.h"

namespace Chrono
{
  using Compute_date::compute_all;
  using Compute_date::get_month_ends;
  using Date_types::Date_struct;
  using Date_types::Invalid_day;
  using Date_types::Month;

  constexpr long year_days = 365;

  void Date::update_all(long dd)
  {
    if (dd < 0)
      throw Invalid_day{};
    eld = dd;
    Date_struct ds = compute_all(dd);
    y = ds.year;
    m = ds.month;
    d = ds.day;
    wd = ds.week_day;
  }

  Date::Date(long dd) : eld(dd)
  {
    update_all(dd);
  }

  void Date::set_days(long dd)
  {
    update_all(dd);
  }

  void Date::add_day(long n)
  {
    if (n < 0)
      throw Negative_Day{};
    update_all(eld + n);
  }

  bool leapyear(long y)
  {
    return (y % 4 == 0);
  }

  void Date::add_year(long n)
  {
    if (n < 0)
      throw Negative_Year{};
    long leap_num = (y + n) / 4 - y / 4;
    long added_days = year_days * n + leap_num;
    if (m <= Month::feb)
    {
      if (leapyear(y))
      {
        if (n % 4 > 0)
          ++added_days;
      }
      else if (leapyear(y + n))
        --added_days;
    }
    update_all(eld + added_days);
  }
  ostream &operator<<(ostream &os, const Date &d)
  {
    return os << d.week_day() << ' ' << d.month() << ' ' << d.day() << ' ' << d.year();
  }
  void Date::add_month(long n)
  {
    if (n < 0)
      throw Negative_Month{};

    long year_to_add = n / 12;
    if (year_to_add > 0)
      add_year(year_to_add);

    n %= 12;

    long added_days = 0;
    vector<long> month_ends = get_month_ends(leapyear(y));
    int current = int(m);
    long current_start = (current > 0) ? month_ends[current - 1] : 0;
    int target = current + n;
    if (target > 11)
    {
      added_days += month_ends[11] - current_start; // we will start again in Jan next year
      month_ends = get_month_ends(leapyear(y + 1));
      current = 0;
      current_start = 0;
      target -= 12; // 0 for January!
    }

    long target_start = (target > 0) ? month_ends[target - 1] : 0;
    long days_in_target = month_ends[target] - target_start;

    added_days += target_start - current_start;
    if (d > days_in_target)
      added_days -= (d - days_in_target);
    update_all(eld + added_days);
  }
  istream &operator>>(istream &is, Date &d)
  {
    int y, m, dd;
    char ch1, ch2, ch3, ch4;
    is >> ch1 >> y >> ch2 >> m >> ch3 >> dd >> ch4;
    if (!is)
      return is;
    if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')')
    {
      is.clear(ios_base::failbit);
      return is;
    }
    d.set_days(0); // Start over from Jan 1 1970
    if (y < 1970)
      throw Date::Negative_Year{};
    d.add_year(y - 1970);
    d.add_month(m - 1);
    d.add_day(dd - 1);
    return is;
  };
} // namespace Chrono
