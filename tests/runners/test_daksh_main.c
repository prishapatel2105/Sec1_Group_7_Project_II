#include "test_framework.h"
#include "test_suites.h"

/*
 * Author: Daksh
 * Inputs: None.
 * Outputs: Runs Eligibility and Selection tests and returns their status.
 * Purpose: Allow Daksh's branch to demonstrate independent module testing.
 */
int main(void)
{
    runEligibilityTests();
    runSelectionTests();
    return testFinish();
}
