#include "myClassesData.h"

Date::Date():
    mDay(0), mMonth(0), mYear(0){
    if(!areValid())
        throw std::invalid_argument(
                        "Arguments must be in the range of date");
}

Date::Date(int r, int g, int b):
    mDay(r), mMonth(g), mYear(b){
    if(!areValid())
        throw std::invalid_argument(
                        "Arguments must be in the range of date");
}

bool Date::areValid() const {
    if(mDay < 0 || mMonth < 0 || mYear < 0
            || mDay > 31 || mMonth > 12 || mYear > 2100)
        return false;
    else
        return true;
}

std::ostream& operator<<(std::ostream &output, const Date &c)
{
    output << "(" << c.day() << ", " << c.month() << ", " << c.year() << ")";
    return output;
}
