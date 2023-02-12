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

TEST_SUITE( "Task 1"
                * doctest::description(
                    "A suite of tests for task 1: Declare SetOpVectorBag<T> as a subclass of VectorBag<T>" )
                * doctest::skip( SKIP_TESTING_TASK_1 ))
{
    SCENARIO( "Task is ready for evaluation" )
    {
        GIVEN("a class hierarchy to find")
        {
            const char *search_string = "class SetOpVectorBag : public VectorBag";
            const char *filename = "set-op-vector-bag.h";

            WHEN("I attempt to access the file it would be declared in")
            {
                std::ifstream input_stream{ filename, std::ios::in };
                THEN("I expect no issues")
                {
                    if ( !input_stream )
                    {
                        FAIL_CHECK( "Test source file could not be opened!" );
                        exit( EXIT_FAILURE );
                    }
                    AND_THEN("further more, I expect the declaration to exist")
                    {
                        // Read the entire file into memory
                        std::string file_contents;
                        std::string current_line;
                        while ( getline( input_stream, current_line ))
                            file_contents += current_line + '\n';
                        input_stream.close( );

                        size_t pos = file_contents.find( search_string );
                        REQUIRE_MESSAGE(( static_cast<int>(pos) > 0 ),
                                        "It appears you have not declared the SubOpVectorBag class. Please do this before attempt to validate this task." );
                    }
                }
            }
        }
    }
}
