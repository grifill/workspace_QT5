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
#include <list>
#include <string>
#include <utility>
#include <map>

#include "MyClasses/myClassesData.h"
#include "MyDict/dict_IIS.h"

auto autoDictFill(std::list<std::pair<Date, int>>& mapFill, int monthStart, int yearStart, int monthCnt, int* massData) {
    for(int i = 0; i < monthCnt; ++i) {
        mapFill.emplace(mapFill.end(), Date(DEFAULT_DAY, monthStart, yearStart), massData[i]);
        monthStart++;
        if(!(monthStart % 13)) {
            yearStart++;
            monthStart = 1;
        }
    }
     return mapFill;
}

void FuncFF() {
    std::list<std::pair<Date, int>> mapVL;
    std::list<std::pair<Date, int>> mapCUR;

    mapVL=autoDictFill(mapVL, START_MONTH, START_YEAR, MONTH_CNT, (int*)vlMass);
    mapCUR=autoDictFill(mapCUR, START_MONTH, START_YEAR, MONTH_CNT, (int*)curMass);

    for (const auto& elem : mapVL) {
        std::cout << elem.first << ": " << elem.second << "\n";
    }
    for (const auto& elem : mapCUR) {
        std::cout << elem.first << ": " << elem.second << "\n";
    }
}

