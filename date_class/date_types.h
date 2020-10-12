#include "../std_lib_facilities.h"

namespace Date_types
{
  enum class Month
  {
    jan,
    feb,
    mar,
    apr,
    may,
    jun,
    jul,
    aug,
    sep,
    oct,
    nov,
    dec
  };
  enum class Week_day
  {
    sunday,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday
  };
  struct Date_struct
  {
    long year;
    Month month;
    long day;
    Week_day week_day;
  };
  class Invalid_day
  {
  };

  const vector<Month> months_in_year{Month::jan, Month::feb, Month::mar, Month::apr, Month::may, Month::jul, Month::jun, Month::aug, Month::sep, Month::oct, Month::nov, Month::dec};

  ostream &operator<<(ostream &os, const Week_day &wd);
  ostream &operator<<(ostream &os, const Month &m);
} // namespace Date_types