#ifndef SELECTION_H
#define SELECTION_H

#include "models.h" // Include the models.h header file for data structures

int isDuplicateRide(const Ride* cart, int rideCount, int rideId); // Function to check if a ride is already in the cart based on ride ID
int generateTicketId(void); // Function to generate a unique ticket ID
int addRideToCart( // Function to add a ride to the cart
	Ride** cart, // Pointer to the pointer of the ride cart
	int* rideCount, // Pointer to the number of rides in the cart
	int* capacity, // Pointer to the capacity of the cart
	const Ride* ride, // Pointer to the Ride structure to be added to the cart
	const User* user // Pointer to the User structure for eligibility check
);
void displayCart(const Ride* cart, int rideCount); // Function to display the rides in the cart
int confirmCheckout(void); // Function to confirm if the user wants to proceed to checkout

#endif