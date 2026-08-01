#ifndef EXIT_MODULE_H
#define EXIT_MODULE_H

#include <stdio.h>

#include "models.h" // Include the models.h header file for data structures

int registerCleanupResources( // Function to register resources for cleanup
	Ride** catalogue, // Pointer to the pointer of the ride catalogue
	Ride** cart, // Pointer to the pointer of the ride cart
	User** user, // Pointer to the pointer of the user
	FILE** openFile // Pointer to the pointer of the open file
);
void clearCleanupRegistration(void); // Function to clear the registered cleanup resources
void cleanupSystem( // Function to clean up the system resources
    Ride** catalogue, // Pointer to the pointer of the ride catalogue
    Ride** cart, // Pointer to the pointer of the ride cart
    User** user, // Pointer to the pointer of the user
    FILE** openFile // Pointer to the pointer of the open file
);
int confirmExit(void); // Function to confirm if the user wants to exit the program
void displayExitSummary(int rideCount); // Function to display the exit summary with the number of rides in the cart
void exitProgram(int status); // Function to exit the program with the given status

#endif