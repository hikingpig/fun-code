#include "compute_date.h"

namespace Compute_date
{
  using Date_types::Date_struct;
  using Date_types::Invalid_day;
  using Date_types::Month;
  using Date_types::months_in_year;
  using Date_types::Week_day;

  constexpr long leap_days = 1461;
  constexpr long start_year = 1968; // start from 1/1/1969, the first year after the leap year 1968

  struct Analyze_result
  {
    long leaps;
    long remain_years;
    long remain_days;
  };
  Analyze_result analyze(long d)
  {
    Analyze_result res;
    res.leaps = d / leap_days;
    res.remain_years = (d - res.leaps * leap_days) / 365;
    res.remain_days = d - (leap_days * res.leaps + res.remain_years * 365);
    return res;
  }
  vector<long> get_month_ends(bool leapyear)
  {
    vector<long> res;
    // leap year will have an extra day
    long extra = 0;
    if (leapyear)
      extra = 1;
    long end = 0;
    for (Month m : months_in_year)
    {
      switch (m)
      {
      case Month::feb:
        res.push_back(end += 28 + extra);
        break;
      case Month::apr:
      case Month::jul:
      case Month::sep:
      case Month::nov:
        res.push_back(end += 30);
        break;
      default:
        res.push_back(end += 31);
        break;
      }
    }
    return res;
  }
  long start_from_1969(long d) // count days from 1/1/1969. 1st Jan 1970 is day 366
  {
    return d += 366;
  }

  Week_day compute_week_day(long d)
  {
    return Week_day((d + 2) % 7); // 1/1/1969 is Wednesday
  }

  long compute_year(const Analyze_result &res)
  {
    if (res.remain_days > 0)
      return 4 * res.leaps + res.remain_years + 1 + start_year;
    else // special case: 31/12 of all year
    {
      return 4 * res.leaps + res.remain_years + start_year;
    }
  }
  struct Month_day
  {
    Month month;
    long day;
  };

  Month_day compute_month_day(const Analyze_result &an)
  {
    Month_day res;
    if (an.remain_days == 0) // special case: 31/12 of all year
    {
      res.month = Month::dec;
      res.day = 31;
      return res;
    }
    bool is_leap = false;
    if (an.remain_years == 3) // leap year
      is_leap = true;

    vector<long> month_ends = get_month_ends(is_leap);

    for (int i = 0; i < month_ends.size(); ++i)
    {
      if (an.remain_days <= month_ends[i])
      {
        res.month = Month(i);
        if (i == 0)
          res.day = an.remain_days;
        else
          res.day = an.remain_days - month_ends[i - 1];

        break;
      }
    }
    return res;
  }

  struct Compute_result
  {
    long year;
    Month month;
    long day;
    Week_day week_day;
  };
  // compute weekday, day, month and years from days counted since 1/1/1970
  Date_struct compute_all(long d)
  {
    if (d < 0)
      throw Invalid_day{};

    Date_struct res;

    d = start_from_1969(d);

    Analyze_result analyze_res = analyze(d);

    res.year = compute_year(analyze_res);

    Month_day md = compute_month_day(analyze_res);

    res.month = md.month;
    res.day = md.day;

    // get week_day
    res.week_day = compute_week_day(d);
    return res;
  }
} // namespace Compute_date