/**
 * milk - Data Structures
 * Missouri State University
 *
 * @file    test_task1.cpp
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Test suite to validate task 1 of this assignment.
 * @version v2022.12.26
 * @date    Spring 2023
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "bag.h"
#include "doctest.h"
#include "csc232.h"
#include "vector-bag.h"

TEST_SUITE( "VectorBag Test Suite"
            * doctest::description( "A suite of tests for verifying the VectorBag" )
            * doctest::skip( !SKIP_TESTING_TASK_1 ))
{
    SCENARIO( "A newly constructed VectorBag" )
    {
        GIVEN( "a brand new VectorBag" )
        {
            csc232::Bag<std::string> *bag = new csc232::VectorBag<std::string>{ };
            WHEN( "we get the current size" )
            {
                int expected{ 0 };
                int actual{ bag->getCurrentSize( ) };
                THEN( "it should report that it contains no items" )
                {
                    CHECK_EQ( expected, actual );
                }
            }

            AND_WHEN( "we check if it is empty" )
            {
                bool actual{ bag->isEmpty( ) };
                THEN( "it should report that it is empty" )
                {
                    CHECK( actual );
                }
            }

            AND_WHEN( "we check the number of occurrences of \"carrots\"" )
            {
                int expected{ 0 };
                int actual{ bag->getFrequencyOf( "carrots" ) };
                THEN( "it should report none" )
                {
                    CHECK_EQ( expected, actual );
                }
            }

            AND_WHEN( "we check if the bag contains \"carrots\"" )
            {
                bool actual{ bag->contains( "carrots" ) };
                THEN( "it should report no" )
                {
                    CHECK_FALSE( actual );
                }
            }

            AND_WHEN( "we convert the bag to a vector" )
            {
                std::size_t expected{ 0 };
                std::size_t actual{ ( bag->toVector( ) ).size( ) };
                THEN( "the vector should be empty" )
                {
                    CHECK_EQ( expected, actual );
                }
            }
        }

    }

    SCENARIO( "A VectorBag with more than one item")
    {
        GIVEN( "a VectorBag with three items")
        {
            csc232::Bag<std::string> *bag = new csc232::VectorBag<std::string>{ };
            bag->add( "carrots" );
            bag->add( "milk" );
            bag->add( "chicken wings" );

            WHEN( "we get the current size" )
            {
                int expected{ 3 };
                int actual{ bag->getCurrentSize( ) };

                THEN( "it should contain three items" )
                {
                    CHECK_EQ( expected, actual );
                }
            }

            AND_WHEN( "we add one item" )
            {
                bag->add( "blue cheese" );
                int expected{ 4 };
                int actual{ bag->getCurrentSize( ) };
                THEN( "we expect the current size to have increased by one" )
                {
                    CHECK_EQ( expected, actual );
                }
            }

            AND_WHEN( "we remove one item" )
            {
                bag->remove( "carrots" );
                int expected{ 2 };
                int actual{ bag->getCurrentSize( ) };
                THEN( "we expect the current size to have decreased by one" )
                {
                    CHECK_EQ( expected, actual );
                }
            }

            AND_WHEN( "we clear the bag" )
            {
                bag->clear();
                int expected{ 0 };
                int actual{ bag->getCurrentSize( ) };
                THEN( "we expect the current size to have decreased by one" )
                {
                    CHECK_EQ( expected, actual );
                }
            }

            AND_WHEN( "we count the number of \"carrots\"" )
            {
                int expected{ 1 };
                int actual{ bag->getFrequencyOf( "carrots" )};
                THEN( "we expect to find one" )
                {
                    CHECK_EQ( expected, actual );
                }
            }

            AND_WHEN( "we see if the bag contains \"carrots\"")
            {
                bool actual{ bag->contains( "carrots" )};
                THEN( "we expect to find one" )
                {
                    CHECK( actual );
                }
            }

            AND_WHEN( "we remove the bunch of \"carrots\"")
            {
                bag->remove( "carrots" );
                THEN( "we expect there to be no more carrots" )
                {
                    CHECK_FALSE( bag->contains( "carrots" ) );
                }
            }

            AND_WHEN( "we add another bunch of \"carrots\"")
            {
                bag->add( "carrots" );
                int expected{ 2 };
                int actual{ bag->getFrequencyOf( "carrots" )};
                THEN( "the count has increased by one" )
                {
                    CHECK_EQ( expected, actual );
                }
            }

            AND_WHEN( "we convert the bag to a vector" )
            {
                std::size_t expected{ 3 };
                std::size_t actual{ ( bag->toVector( ) ).size( ) };
                THEN( "the vector should contain three items" )
                {
                    CHECK_EQ( expected, actual );
                }
            }
        }
    }
}
