#ifndef FILE_IO_H
#define FILE_IO_H

#include "models.h" // Include the models.h header file for data structures

int loadRideData(const char* filename, Ride** rides, int* rideCount); // Function to load ride data from a file into an array of Ride structures
int saveTicketDetails( // Function to save ticket details to a file
	const char* filename, // Name of the file to save ticket details
	const User* user, // Pointer to the User structure containing user details
	const Ride* cart, // Pointer to the array of rides in the cart
	int rideCount, // Number of rides in the cart
	const Ticket* ticket // Pointer to the Ticket structure containing billing details
);

#endif