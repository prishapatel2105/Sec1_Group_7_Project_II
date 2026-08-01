#ifndef USER_H
#define USER_H

#include "models.h" // Include the models.h header file for data structures

int validateUserName(const char* name); // Function to validate the user's name
int validateUserNumber(int value, int minimum, int maximum); // Function to validate a numerical value within a specified range
int initializeUser(User* user, const char* name, int age, int height, int weight); // Function to initialize a User structure with the provided details
int getUserDetails(User* user); // Function to get user details from input

#endif