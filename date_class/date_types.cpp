#include "date_types.h"

namespace Date_types
{
  ostream &operator<<(ostream &os, const Week_day &wd)
  {
    switch (wd)
    {
    case Week_day::monday:
      os << "Mon";
      break;
    case Week_day::tuesday:
      os << "Tue";
      break;
    case Week_day::wednesday:
      os << "Wed";
      break;
    case Week_day::thursday:
      os << "Thu";
      break;
    case Week_day::friday:
      os << "Fri";
      break;
    case Week_day::saturday:
      os << "Sat";
      break;
    case Week_day::sunday:
      os << "Sun";
      break;
    }
    return os;
  }

  ostream& operator<<(ostream &os, const Month& m) {
    switch(m) {
      case Month::jan:
        os << "Jan";
        break;
      case Month::feb:
        os << "Feb";
        break;
      case Month::mar:
        os << "Mar";
        break;
      case Month::apr:
        os << "Apr";
        break;
      case Month::may:
        os << "May";
        break;
      case Month::jul:
        os << "Jul";
        break;
      case Month::jun:
        os << "Jun";
        break;
      case Month::aug:
        os << "Aug";
        break;
      case Month::sep:
        os << "Sep";
        break;
      case Month::oct:
        os << "Oct";
        break;
      case Month::nov:
        os << "Nov";
        break;
      case Month::dec:
        os << "Dec";
        break;
    }
    return os;
  }
} // namespace Date_types