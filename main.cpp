/**
 * CSC232 - Data Structures
 * Missouri State University
 *
 * @file    main.cpp
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Entry-point of the main target.
 * @version v2022.12.26
 * @date    Spring 2023
 */

#include <iostream>
#include <string>
#include "set-op-vector-bag.h"
#include "csc232.h"

#if !SKIP_TESTING_TASK_5
using csc232::SetOpVectorBag;
#endif

template <typename T>
void printBag( VectorBag<T> bag )
{
    std::vector<T> data = bag.toVector();
    std::cout << "[";
    size_t num_items{ data.size( ) };
    if ( num_items > 0 )
    {
        for (size_t i{ 0 }; i < num_items - 1; ++i )
        {
           std::cout << data.at( i ) << ", ";
        }
    std::cout << data.at( num_items - 1 );
    }
    std::cout << "]" << std::endl;
}

int main( )
{
#if !SKIP_TESTING_TASK_1

    SetOpVectorBag<std::string> lhs;
    SetOpVectorBag<std::string> rhs;
    SetOpVectorBag<std::string> result;

    lhs.add( "a" );
    lhs.add( "b" );
    lhs.add( "c" );

    rhs.add( "b" );
    rhs.add( "b" );
    rhs.add( "d" );
    rhs.add( "e" );

#if !SKIP_TESTING_TASK_2
    result = lhs.unionWith( rhs );

    std::cout << "lhs                         = ";
    printBag( lhs );
    std::cout << "rhs                         = ";
    printBag( rhs );
    std::cout << "union of lhs and rhs        = ";
    printBag( lhs.unionWith( rhs ) );
    std::cout << "it should be                = [a, b, c, b, b, d, e]" << std::endl;
#endif

#if !SKIP_TESTING_TASK_3
    std::cout << "intersection of lhs and rhs = ";
    printBag( lhs.intersectionWith( rhs ) );
    std::cout << "it should be                = [b]" << std::endl;
#endif

#if !SKIP_TESTING_TASK_4
    std::cout << "difference of lhs and rhs   = ";
    printBag( lhs.differenceWith( rhs ) );
    std::cout << "it should be                = [a, c]" << std::endl;
#endif

#endif

    return 0;
}
