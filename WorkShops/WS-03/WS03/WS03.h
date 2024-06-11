#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H
#define MAX_LENGTH 20

struct Customer {
    char firstName[MAX_LENGTH];
    char lastName[MAX_LENGTH];
    char address[MAX_LENGTH];
    char city[MAX_LENGTH];
    char province[MAX_LENGTH];
    char postalCode[MAX_LENGTH];
};

void getCustomerDetails(struct Customer* customer);
int checkStr(char* str);
int validatePostalCode(char* pos);
int validateString(char* Str);
#endif 
