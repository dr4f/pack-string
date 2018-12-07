#ifndef TEST_HELPERS_HEADER
#define TEST_HELPERS_HEADER

#include <iostream>

/* Test helper macro that prints out if a condition passed or failed and the line number
 */
#define TEST_DEBUG_COND(cond) std::cout << "Test for '" << #cond << "' at line " << __LINE__ << (cond ? " passed.\n" : " failed.\n")

/* Test helper macro that increments a variable if a test fails.
 */
#define TEST_CHECK_COND(cond, variable) variable += (cond ? 0 : 1)

/* Combines prevous two macros
 */
#define TEST_CHECK_ALL(cond, variable) TEST_DEBUG_COND(cond); TEST_CHECK_COND(cond, variable)

#endif // TEST_HELPERS_HEADER
