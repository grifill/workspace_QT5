/**
 * ---------------------------------------------------------------------------
 * Copyright (c) 2025 Gregory Filatov
 * All rights reserved.
 *
 * \file   myClassesData.cpp
 *
 * \author Gregory Filatov
 * \date   09 April 2025
 * \version 1.0
 *
 * \brief  Contains my Data classes
 *
 * Module: myClassesData.cpp
 *
 * Purpose: Lib-file
 *
 * Functionality:
 *     Environment
 * ---------------------------------------------------------------------------
 */
#include "myClassesData.h"

Date::Date():
    mDay(0), mMonth(0), mYear(0){
    if(!areValid())
        throw std::invalid_argument(
                        "Arguments must be in the range of date");
}

Date::Date(int d, int m, int y):
    mDay(d), mMonth(m), mYear(y){
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

std::string Date::toString() const {
    return std::to_string(mMonth) + "." + std::to_string(mYear);
}

int Date::forComparator() const {
    return mYear*2000 + mMonth*100 + mDay;
}

std::ostream& operator<<(std::ostream &output, const Date &c)
{
    output << "(" << c.day() << ", " << c.month() << ", " << c.year() << ")";
    return output;
}

