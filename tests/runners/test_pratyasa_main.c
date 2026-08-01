#include "test_framework.h"
#include "test_suites.h"

/*
 * Author: Pratyasa
 * Inputs: None.
 * Outputs: Runs File and Exit tests and returns their status.
 * Purpose: Allow Pratyasa's branch to demonstrate independent module testing.
 */
int main(void)
{
    runFileIoTests();
    runExitModuleTests();
    return testFinish();
}
