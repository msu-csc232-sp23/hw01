/**
 * CSC232 - Data Structures
 * Missouri State University
 *
 * @file    csc232.h
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Useful libraries and function declarations for CSC232 assignments.
 * @version v2022.12.26
 * @date    Spring 2023
 */

#ifndef CSC232
#define CSC232

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE !FALSE
#endif

// Set this macro to the value of FALSE to test Task 1
#define SKIP_TESTING_TASK_1 TRUE
// Set this macro to the value of FALSE to test Task 2
#define SKIP_TESTING_TASK_2 TRUE
// Set this macro to the value of FALSE to test Task 3
#define SKIP_TESTING_TASK_3 TRUE
// Set this macro to the value of FALSE to test Task 4
#define SKIP_TESTING_TASK_4 TRUE
// Set this macro to the value of FALSE to test Task 5
#define SKIP_TESTING_TASK_5 TRUE

#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <memory>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

// Include template class implementation source files
#include "bag.h"
#include "vector-bag.cpp"
#include "set-op-vector-bag.cpp"

#if !SKIP_TESTING_TASK_5
using csc232::Bag;
using csc232::VectorBag;
using csc232::SetOpVectorBag;
#endif

// Declare template usage to inform compiler what code to actually implement for the template
template class VectorBag<std::string>;

#if !SKIP_TESTING_TASK_1
template class SetOpVectorBag<std::string>;
#endif

#endif
