#include "compute_date.h"
/*
- The Date class is designed centering around days elapsed since Jan 1 1970
- It day, month and year and weekday are all computed from this elapsed days
- To add month and years, we find the added days and compute everything again
*/

namespace Chrono
{
  class Date
  {
  public:
    class Invalid
    {
    };
    class Negative_Day
    {
    };
    class Negative_Year
    {
    };
    class Negative_Month
    {
    };
    Date(long dd);
    long year() const { return y; }
    long day() const { return d; }
    long days() const { return eld; }
    Date_types::Month month() const { return m; }
    Date_types::Week_day week_day() const { return wd; }

    void set_days(long n);
    void add_day(long n);
    void add_year(long n);
    void add_month(long n);

  private:
    long eld{0}; // elapsed days since 1/1/1970
    long y{0};
    Date_types::Month m{};
    long d{0};
    Date_types::Week_day wd{};
    void update_all(long days);
  };

  ostream &operator<<(ostream &os, const Date &d);
  istream &operator>>(istream &is, Date &d);
} // namespace Chrono