/**
 * ---------------------------------------------------------------------------
 * Copyright (c) 2025 Gregory Filatov
 * All rights reserved.
 *
 * \file   myClassesData.h
 *
 * \author Gregory Filatov
 * \date   09 April 2025
 * \version 1.0
 *
 * \brief  Contains my Data classes
 *
 * Module: myClassesData.h
 *
 * Purpose: Lib-file
 *
 * Functionality:
 *     Environment
 * ---------------------------------------------------------------------------
 */

#ifndef MYCLASSESDATA_H
#define MYCLASSESDATA_H

#include <iostream>
#include <stdexcept>

class Date{
public:
    Date();
    Date(int d, int m, int y);
    int day() const {return mDay;}
    int month() const {return mMonth;}
    int year() const {return mYear;}
    bool areValid() const;
private:
    int mDay;
    int mMonth;
    int mYear;
};

std::ostream& operator<<(std::ostream &output, const Date &c);

class Comparator {
public:
    bool operator()(const Date& c1, const Date& c2) const {
        return c1.day() + c1.month() + c1.year() <
            c2.day() + c2.month() + c2.year();
    }
};

#endif // MYCLASSESDATA_H
