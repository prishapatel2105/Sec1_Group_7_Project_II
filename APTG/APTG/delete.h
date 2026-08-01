#ifndef DELETE_H
#define DELETE_H

#include "models.h" // Include the models.h header file for data structures

void displaySelectedRides(const Ride* cart, int rideCount); // Function to display the selected rides in the cart
int deleteRideFromCart(Ride* cart, int* rideCount, int rideId); // Function to delete a ride from the cart based on ride ID
int deleteRideAtIndex(Ride* cart, int* rideCount, int oneBasedIndex); // Function to delete a ride from the cart based on a one-based index

#endif