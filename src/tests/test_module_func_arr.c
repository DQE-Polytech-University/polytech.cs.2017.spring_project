#include "unity.h"
#include "unity_fixture.h"
#include "module.h"

#define SIZE 5

TEST_GROUP(TestSqrArr);

TEST_GROUP_RUNNER(TestSqrArr)
{
    RUN_TEST_CASE(TestSqrArr, test_clear_array);
    RUN_TEST_CASE(TestSqrArr, test_sqr_array_rand);
}

TEST_SETUP(TestSqrArr)
{
}

TEST_TEAR_DOWN(TestSqrArr)
{
}


TEST(TestSqrArr, test_clear_array)
{
    float x[SIZE] = {1.0f, 2.4f, 3.8f, 9.12f, 3.14f};
    float empty[SIZE] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
    clear_arr(x, SIZE);
    TEST_ASSERT_EQUAL_FLOAT_ARRAY(empty, x, SIZE);
}

TEST(TestSqrArr, test_sqr_array_rand)
{
    float x[SIZE] = {1.0f, 2.4f, 3.8f, 9.12f, 3.14f};
    float empty[SIZE] = {1.0f, 5.76f, 14.44f, 83.1744f, 9.8596f};
    sqr_arr(x, SIZE);
    TEST_ASSERT_EQUAL_FLOAT_ARRAY(empty, x, SIZE);
}