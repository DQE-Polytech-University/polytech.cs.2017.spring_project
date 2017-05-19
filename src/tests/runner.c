/** @file runner.c
 *  @brief Tests runner
 *
 *  This is an example. Please, change the description.
 *
 *  @author Name Surname - xxx@spbstu.ru
 */

#include "unity.h"
#include "unity_fixture.h"

/** @brief Run the groups of the tests.
 *
 *  The function sequentially runs the groups of the test.
 *
 *  @return void
 */
static void RunAllTests(void)
{
    RUN_TEST_GROUP(TestSqr);
    RUN_TEST_GROUP(TestSqrArr);
}

/** @brief Tests entrypoint.
 *
 *  This is the entrypoint for the program under tests.
 *
 *  @param[in] argc An argument count.
 *  @param[in] argv An argument vector.
 *  @return int
 */
int main(int argc, const char * argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}
