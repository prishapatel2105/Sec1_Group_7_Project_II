#include "test_framework.h"
#include "test_suites.h"

/*
 * Author: Prisha
 * Inputs: None.
 * Outputs: Runs User and Ride Display tests and returns their status.
 * Purpose: Allow Prisha's branch to demonstrate independent module testing.
 */
int main(void)
{
    runUserTests();
    runRideDisplayTests();
    return testFinish();
}
