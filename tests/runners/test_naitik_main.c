#include "test_framework.h"
#include "test_suites.h"

/*
 * Author: Naitik
 * Inputs: None.
 * Outputs: Runs Delete and Billing tests and returns their status.
 * Purpose: Allow Naitik's branch to demonstrate independent module testing.
 */
int main(void)
{
    runDeleteTests();
    runBillingTests();
    return testFinish();
}
