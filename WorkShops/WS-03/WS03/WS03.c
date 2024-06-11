#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "WS03.h"

void getCustomerDetails(struct Customer* customer) {

    int validateFName = 0;
    do {
        char input[128];
        printf("Enter your first name: ");
        fgets(input, sizeof(input), stdin);
        int check = 0;
        check = checkStr(input);
        size_t inputLength = strlen(input);
        if (!check) {
            printf("Invalid Entry: ");
        }
        else {
            input[inputLength - 1] = '\0';
            strncpy(customer->firstName, input, sizeof(customer->firstName) - 1);
            validateFName = 1;
        }
    } while (!validateFName);

    int validateLName = 0;
    do {
        char input[128];
        printf("Enter your last name: ");
        fgets(input, sizeof(input), stdin);
        int check = 0;
        check = checkStr(input);
        size_t inputLength = strlen(input);
        if (!check) {
            printf("Invalid Entry: ");
        }
        else {
            input[inputLength - 1] = '\0';
            strncpy(customer->lastName, input, sizeof(customer->lastName) - 1);
            validateLName = 1;
        }
    } while (!validateLName);

    int validateAddress = 0;
    do {
        char input[128];
        printf("Enter your street address: ");
        fgets(input, sizeof(input), stdin);
        int check = 0;
        check = checkStr(input);
        size_t inputLength = strlen(input);
        if (!check) {
            printf("Invalid Entry: ");
        }
        else {
            input[inputLength - 1] = '\0';
            strncpy(customer->address, input, sizeof(customer->address) - 1);
            validateAddress = 1;
        }
    } while (!validateAddress);

    int validateCity = 0;
    do {
        char input[128];
        printf("Enter your city: ");
        fgets(input, sizeof(input), stdin);
        int check = 0;
        check = checkStr(input);
        size_t inputLength = strlen(input);
        if (!check) {
            printf("Invalid Entry: ");
        }
        else {
            input[inputLength - 1] = '\0';
            strncpy(customer->city, input, sizeof(customer->city) - 1);
            validateCity = 1;
        }
    } while (!validateCity);

    int validateProvince = 0;
    do {
        char input[128];
        printf("Enter your province: ");
        fgets(input, sizeof(input), stdin);
        int check = 0;
        check = checkStr(input);
        size_t inputLength = strlen(input);
        if (!check) {
            printf("Invalid Entry: ");
        }
        else {
            input[inputLength - 1] = '\0';
            strncpy(customer->province, input, sizeof(customer->province) - 1);
            validateProvince = 1;
        }
    } while (!validateProvince);

    char pos[10];
    int validatePostalCode = 0;

    do {
        printf("Enter your postal code: ");
        fgets(pos, sizeof(pos), stdin);
        size_t inputLength = strlen(pos);

        if (inputLength > 0 && pos[inputLength - 1] == '\n') {
            pos[inputLength - 1] = '\0';

            if (pos[0] == '\0') {
                printf("Invalid Entry: ");
            }
            else {
                int check = isValid(pos);
                if (check) {
                    validatePostalCode = 1;
                    strcpy(customer->postalCode, pos);
                }
                else {
                    printf("Invalid Entry: ");
                    validatePostalCode = 0;
                }
            }
        }
    } while (!validatePostalCode);
}

int isValid(char* pos) {
    size_t length = strlen(pos);
    int isPostalCodeValid = 0;

    if (length == 6) {
        if (isalpha(pos[0]) && isdigit(pos[1]) && isalpha(pos[2]) && isdigit(pos[3]) && isalpha(pos[4]) && isdigit(pos[5])) {
            for (int i = 5; i >= 3; i--) {
                pos[i + 1] = pos[i];
            }
            pos[3] = ' ';
            for (int i = 0; i < length + 1; i++) {
                pos[i] = toupper(pos[i]);
            }
            pos[8] = '\0';
            return 1;
        }
    }
    else if (length == 7) {
        if (isalpha(pos[0]) && isdigit(pos[1]) && isalpha(pos[2]) && pos[3] == ' ' && isdigit(pos[4]) && isalpha(pos[5]) && isdigit(pos[6])) {

            for (int i = 0; i < length; i++) {
                pos[i] = toupper(pos[i]);
            }
            pos[8] = '\0';
            return 1;
        }
    }
    return 0;
}

int checkStr(char* string) {
    size_t inputLength = strlen(string);
    if (inputLength > 1 && string[0] != '\n') {
        return 1;
    }
    else if (inputLength == 1 && string[0] == '\n') {
        return 0;
    }
    else {
        return 0;
    }
}

int validatePostalCode(char* pos) {
    return isValid(pos);
}

int validateString(char* str) {
    int result = 0;
    int resBool = 0;
    result = checkStr(str);
    if (result) {
        resBool = 1;
    }
    else {
        resBool = 0;
    }
    return resBool;
}

int main() {
    struct Customer customer;
    getCustomerDetails(&customer);

    printf("\nYou entered:\n");
    printf("%s %s\n", customer.firstName, customer.lastName);
    printf("%s,\n", customer.address);
    printf("%s, %s,\n", customer.city, customer.province);
    printf("%s\n", customer.postalCode);
    return 0;
}