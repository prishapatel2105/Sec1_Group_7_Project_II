#ifndef TEST_FRAMEWORK_H
#define TEST_FRAMEWORK_H

#include <math.h>
#include <stdio.h>
#include <string.h>

void testBegin(const char *name);
void testPass(void);
void testFail(
    const char *expression,
    const char *file,
    int line,
    const char *details
);
int testFinish(void);

#define RUN_TEST(functionName) \
    do { \
        testBegin(#functionName); \
        functionName(); \
        testPass(); \
    } while (0)

#define ASSERT_TRUE(expression) \
    do { \
        if (!(expression)) { \
            testFail(#expression, __FILE__, __LINE__, "Expected true"); \
            return; \
        } \
    } while (0)

#define ASSERT_FALSE(expression) ASSERT_TRUE(!(expression))

#define ASSERT_INT_EQ(expected, actual) \
    do { \
        int expectedValue = (expected); \
        int actualValue = (actual); \
        if (expectedValue != actualValue) { \
            char detailBuffer[128]; \
            (void)snprintf( \
                detailBuffer, \
                sizeof(detailBuffer), \
                "Expected %d but received %d", \
                expectedValue, \
                actualValue \
            ); \
            testFail(#actual, __FILE__, __LINE__, detailBuffer); \
            return; \
        } \
    } while (0)

#define ASSERT_FLOAT_NEAR(expected, actual, tolerance) \
    do { \
        float expectedValue = (expected); \
        float actualValue = (actual); \
        float toleranceValue = (tolerance); \
        if (fabsf(expectedValue - actualValue) > toleranceValue) { \
            char detailBuffer[160]; \
            (void)snprintf( \
                detailBuffer, \
                sizeof(detailBuffer), \
                "Expected %.4f but received %.4f", \
                expectedValue, \
                actualValue \
            ); \
            testFail(#actual, __FILE__, __LINE__, detailBuffer); \
            return; \
        } \
    } while (0)

#define ASSERT_STR_EQ(expected, actual) \
    do { \
        const char *expectedValue = (expected); \
        const char *actualValue = (actual); \
        if (expectedValue == NULL || actualValue == NULL \
            || strcmp(expectedValue, actualValue) != 0) { \
            testFail(#actual, __FILE__, __LINE__, "Strings are not equal"); \
            return; \
        } \
    } while (0)

#endif
