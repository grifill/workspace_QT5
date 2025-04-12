#include <stdint.h>
#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <time.h>
#include <stdexcept>

#include "myClassesData.h"

void DictF() {
    std::map<Date, int, Comparator> myMap;
    myMap[Date(10, 01, 2024)] = 10000;
    myMap[Date(10, 02, 2024)] = 20000;
    myMap[Date(10, 03, 2024)] = 30000;
    myMap[Date(10, 04, 2024)] = 40000;
    myMap[Date(10, 05, 2024)] = 50000;
    myMap[Date(10, 06, 2024)] = 60000;

    std::map<Date, int>::iterator it;
    for (it = myMap.begin(); it != myMap.end(); ++it)
        std::cout << it->first << " " << it->second << '\n';
}

