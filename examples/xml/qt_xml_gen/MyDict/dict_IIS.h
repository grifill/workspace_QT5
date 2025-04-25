/**
 * ---------------------------------------------------------------------------
 * Copyright (c) 2025 Gregory Filatov
 * All rights reserved.
 *
 * \file   dict_IIS.h
 *
 * \author Gregory Filatov
 * \date   14 April 2025
 * \version 1.0
 *
 * \brief  Contains my Dictionary examples
 *
 * Module: dict_IIS.h
 *
 * Purpose: Example-file
 *
 * Functionality:
 *     Environment
 * ---------------------------------------------------------------------------
 */

#ifndef DICT_IIS_H
#define DICT_IIS_H

//
#define DEFAULT_DAY (10)
#define START_MONTH (9)
#define START_YEAR  (2022)

//
#define MONTH_CNT   (32)

//
const int vlMass[MONTH_CNT] = {650000, 675000, 675000, 675000,
                               675000, 725000, 750000, 750000, 800000, 800000, 800000, 830000, 830000, 1000000, 1000000, 1000000,
                               1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 2000000, 2000000, 2000000,
                               2000000, 2000000, 2000000, 2000000};

const int curMass[MONTH_CNT] = {500000, 600000, 625000, 650000,
                               650000, 720000, 820000, 855000, 960000, 1015000, 1025000, 1185000, 1270000, 1480000, 1575000, 1505000,
                               1595000, 1800000, 2000000, 2200000, 2250000, 2215000, 2200000, 1950000, 1925000, 3015000, 3000000, 2850000,
                               3200000, 3325000, 3450000, 3100000};

#endif // DICT_IIS_H





