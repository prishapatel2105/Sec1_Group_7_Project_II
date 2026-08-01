#ifndef RIDE_DISPLAY_H
#define RIDE_DISPLAY_H

#include "models.h" // Include the models.h header file for data structures

int buildRideNameTable( // Function to build a table of ride names from an array of Ride structures
	const Ride rides[], // Pointer to the array of Ride structures
	int rideCount, // Number of rides in the array
	char rideNames[][RIDE_NAME_LENGTH], // 2D array to store the ride names
	int nameCapacity // Capacity of the rideNames array
);
void displayRides(const Ride rides[], int rideCount); // Function to display the list of rides with their details
const Ride* getRideById(const Ride rides[], int rideCount, int rideId); // Function to retrieve a ride by its ID from an array of Ride structures

#endif