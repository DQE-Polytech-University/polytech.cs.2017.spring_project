#include "unity.h"
#include "unity_fixture.h"

static void RunAllTests(void)
{
    RUN_TEST_GROUP(TestSqr);
    RUN_TEST_GROUP(TestSqrArr);
}

int main(int argc, const char * argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}