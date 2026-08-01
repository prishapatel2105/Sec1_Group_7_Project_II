#ifndef MODELS_H
#define MODELS_H

#define USER_NAME_LENGTH 50 // Maximum length for user names
#define RIDE_NAME_LENGTH 50 // Maximum length for ride names
#define MAX_RIDES 100 // Maximum number of rides in the catalogue
#define MAX_CART_RIDES 10 // Maximum number of rides in the user's cart

#define MIN_USER_AGE 1 // Minimum age for users
#define MAX_USER_AGE 120 // Maximum age for users
#define MIN_USER_HEIGHT_CM 30 // Minimum height for users in centimeters
#define MAX_USER_HEIGHT_CM 250 // Maximum height for users in centimeters
#define MIN_USER_WEIGHT_KG 2 // Minimum weight for users in kilograms
#define MAX_USER_WEIGHT_KG 300 // Maximum weight for users in kilograms

#define DISCOUNT_RIDE_THRESHOLD 5 // Minimum number of rides in the cart to qualify for a discount
#define DISCOUNT_PERCENTAGE 20.0f // Discount percentage applied when the ride count threshold is met

typedef struct User { // Structure to represent a user
    char name[USER_NAME_LENGTH]; // User's name
    int age; // User's age
    int height; // User's height in centimeters
    int weight; // User's weight in kilograms
} User;

typedef struct Ride { // Structure to represent a ride
	int id; // Unique identifier for the ride
	char name[RIDE_NAME_LENGTH]; // Name of the ride
	float price; // Price of the ride
	int minAge; //  Minimum age required to access the ride
	int minHeight; // Minimum height required to access the ride
    int maxHeight; // Maximum height allowed to access the ride
    int maxWeight; // Maximum weight allowed to access the ride
    int available; // Availability status of the ride
} Ride; // Structure to represent a ride

typedef struct Ticket { // Structure to represent a ticket
    int ticketId; // Unique identifier for the ticket
    int rideCount; // Number of rides in the ticket
    float subtotal; // Subtotal amount before discount
    float discountPercentage; // Discount percentage applied
    float discountAmount; // Discount amount applied
	float finalTotal; // Final total amount after discount
} Ticket;

#endif