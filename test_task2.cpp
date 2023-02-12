/**
 * CSC232 - Data Structures
 * Missouri State University
 *
 * @file    test_task1.cpp
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Test suite to validate task 1 of this assignment.
 * @version v2022.12.26
 * @date    Spring 2023
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "csc232.h"
#include "doctest.h"

#if !SKIP_TESTING_TASK_5
using csc232::SetOpVectorBag;
#endif

using std::string;

TEST_SUITE("Union Test Suite"
           * doctest::description("A suite of tests for the union operation")
           * doctest::skip( SKIP_TESTING_TASK_2 ) )
{
    SCENARIO("Testing the union of two bags")
    {
        GIVEN( "Two SetOpVectorBags as configured in the exercises" )
        {
#if !SKIP_TESTING_TASK_2
            SetOpVectorBag<string> a{ };
            a.add( "a" );
            a.add( "b" );
            a.add( "c" );

            SetOpVectorBag<string> b{ };
            b.add( "b" );
            b.add( "b" );
            b.add( "d" );
            b.add( "e" );

            WHEN( "I examine the the union between the two bags a and b" )
            {
                SetOpVectorBag<string> result{ a.unionWith( b ) };

                THEN( "I expect the result to contain all the items contained in both a and b" )
                {
                    size_t expected_size{ 7 };
                    size_t actual_size{ result.toVector( ).size( ) };
                    REQUIRE_EQ( expected_size, actual_size );

                    int expected_freq_a{ 1 };
                    int expected_freq_b{ 3 };
                    int expected_freq_c{ 1 };
                    int expected_freq_d{ 1 };
                    int expected_freq_e{ 1 };

                    int actual_freq_a{ result.getFrequencyOf( "a" ) };
                    int actual_freq_b{ result.getFrequencyOf( "b" ) };
                    int actual_freq_c{ result.getFrequencyOf( "c" ) };
                    int actual_freq_d{ result.getFrequencyOf( "d" ) };
                    int actual_freq_e{ result.getFrequencyOf( "e" ) };

                    REQUIRE_EQ( expected_freq_a, actual_freq_a );
                    REQUIRE_EQ( expected_freq_b, actual_freq_b );
                    REQUIRE_EQ( expected_freq_c, actual_freq_c );
                    REQUIRE_EQ( expected_freq_d, actual_freq_d );
                    REQUIRE_EQ( expected_freq_e, actual_freq_e );
                }
            }
#endif
        }
    }
}
