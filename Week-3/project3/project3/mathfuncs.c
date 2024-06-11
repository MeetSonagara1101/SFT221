#include <stdio.h>
#include "mathfuncs.h"

double square(double n)
{
    return n * n;
}

double cube(double n)
{
    return n * n * n;
}

int main() {

    printf("square of 2 is %lf \n", square(2));
    printf("cube of 3 is %lf", cube(3));

}