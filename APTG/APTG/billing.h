#ifndef BILLING_H
#define BILLING_H

#include "models.h" // Include the models.h header file for data structures

float calculateTotal(const Ride* cart, int rideCount); // Function to calculate the total cost of rides in the cart
float calculateDiscountAmount(float subtotal, int rideCount); // Function to calculate the discount amount based on subtotal and ride count
int billingGenerateTicketId(void); // Function to generate a unique ticket ID
int prepareTicket( // Function to prepare a ticket with billing details
	const Ride* cart, // Pointer to the array of rides in the cart
	int rideCount, // Number of rides in the cart
	int sessionTicketId, // Session ticket ID for the current transaction
	Ticket* ticket // Pointer to the Ticket structure to store the billing details
);
void displayBill( // Function to display the billing details to the user
	const User* user, // Pointer to the User structure containing user details
	const Ride* cart, // Pointer to the array of rides in the cart
	int rideCount, // Number of rides in the cart
	const Ticket* ticket // Pointer to the Ticket structure containing billing details
);

#endif