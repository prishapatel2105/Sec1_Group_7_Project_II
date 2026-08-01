#include "test_framework.h"

static int assertionsFailed = 0;
static int testsCompleted = 0;
static int currentTestFailed = 0;
static const char *currentTestName = NULL;

/*
 * Author: Prisha (Team Lead)
 * Inputs: Human-readable test function name.
 * Outputs: Resets the per-test state and prints the running test.
 * Purpose: Start one framework-managed test case.
 */
void testBegin(const char *name)
{
    currentTestName = name;
    currentTestFailed = 0;
    printf("[ RUN      ] %s\n", name);
}

/*
 * Author: Prisha (Team Lead)
 * Inputs: Current test state.
 * Outputs: Counts and prints a pass unless an assertion already failed.
 * Purpose: Finish one framework-managed test case.
 */
void testPass(void)
{
    ++testsCompleted;
    if (!currentTestFailed) {
        printf("[       OK ] %s\n", currentTestName);
    }
}

/*
 * Author: Prisha (Team Lead)
 * Inputs: Failed expression, source file/line, and optional details.
 * Outputs: Records and prints one assertion failure.
 * Purpose: Produce traceable evidence for TDD Red and regression failures.
 */
void testFail(
    const char *expression,
    const char *file,
    int line,
    const char *details
)
{
    ++assertionsFailed;
    currentTestFailed = 1;
    printf("[  FAILED  ] %s\n", currentTestName);
    printf("             %s:%d: %s (%s)\n",
           file,
           line,
           expression,
           details != NULL ? details : "");
}

/*
 * Author: Prisha (Team Lead)
 * Inputs: Accumulated framework counters.
 * Outputs: Prints the final summary and returns EXIT_SUCCESS-style 0 or failure-style 1.
 * Purpose: Let Visual Studio, CTest, and command-line builds detect a failing suite.
 */
int testFinish(void)
{
    printf("\nTests completed: %d\n", testsCompleted);
    printf("Assertion failures: %d\n", assertionsFailed);
    return assertionsFailed == 0 ? 0 : 1;
}
