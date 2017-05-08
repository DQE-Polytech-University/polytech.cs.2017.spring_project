#include "unity.h"
#include "unity_fixture.h"
#include "module.h"

TEST_GROUP(TestSqr);

TEST_GROUP_RUNNER(TestSqr)
{
    RUN_TEST_CASE(TestSqr, test_sqr_func_0);
    RUN_TEST_CASE(TestSqr, test_sqr_func_float_2p4);
}

TEST_SETUP(TestSqr)
{
}

TEST_TEAR_DOWN(TestSqr)
{
}

TEST(TestSqr, test_sqr_func_0)
{
    float x = 0.0f;
    float result = sqr(x);
    TEST_ASSERT_EQUAL_FLOAT(x, result);
}

TEST(TestSqr, test_sqr_func_float_2p4)
{
    float x = 2.4f;
    float result = sqr(x);
    TEST_ASSERT_EQUAL_FLOAT(x*x, result); 
}