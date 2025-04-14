/**
 * ---------------------------------------------------------------------------
 * Copyright (c) 2025 Gregory Filatov
 * All rights reserved.
 *
 * \file   dict_IIS.cpp
 *
 * \author Gregory Filatov
 * \date   14 April 2025
 * \version 1.0
 *
 * \brief  Contains my Dictionary examples
 *
 * Module: dict_IIS.cpp
 *
 * Purpose: Example-file
 *
 * Functionality:
 *     Environment
 * ---------------------------------------------------------------------------
 */
#include <stdint.h>
#include <iostream>
#include <map>
#include <string>

#include "MyClasses/myClassesData.h"
#include "MyDict/dict_IIS.h"

void DictF() {
    std::map<Date, int, Comparator> myMap;
    int month = START_MONTH;
    int year = START_YEAR;

    for(int i = 0; i < MONTH_CNT; ++i) {
        myMap.insert({Date(DEFAULT_DAY, month, year), vlMass[i]});
        month++;
        if(!(month % 13)) {
            year++;
            month = 1;
        }
    }

    std::map<Date, int>::iterator it;
    for (it = myMap.begin(); it != myMap.end(); ++it)
        std::cout << it->first << " " << it->second << '\n';
}

