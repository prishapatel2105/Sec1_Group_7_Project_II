#ifndef ELIGIBILITY_H
#define ELIGIBILITY_H

#include <stddef.h> // For size_t

#include "models.h" // Include the models.h header file for data structures

int evaluateEligibility( // Function to evaluate the eligibility of a user for a specific ride
	const User* user, // Pointer to the User structure containing user details
	const Ride* ride, // Pointer to the Ride structure containing ride details
	char* reason, // Pointer to a character array to store the reason for ineligibility
	size_t reasonSize // Size of the reason character array
);
int checkEligibility(const User* user, const Ride* ride); // Function to check if a user meets the eligibility criteria for a specific ride

#endif