/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #4
Full Name  : Meet Hitesh Sonagara
Student ID#: 122208226
Email      : msonagara@myseneca.ca
Section    : ZDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_FACTORIALS 10000
#define NUM_FACTS 100

struct FactorialResults
{
	int results[MAX_FACTORIALS];
	int numResults;
};

int factorial(const int n)
{
	return (n <= 1) ? 1 : n * factorial(n - 1);
}
//int reduceFactorial(const int n)
//{
//    return (n <= 1) ? 1 : (n-1) * reduceFactorial(n - 2);
//}

void computeFactorials(struct FactorialResults* results, int numFactorials)
{
	int i;
	for (i = 0; i < numFactorials; i++)
	{
		// Changed to use -> to access struct members
		results->results[i] = factorial(i);
	}
	// Changed to use ->
	results->numResults = numFactorials;
}

int main(void)
{
	struct FactorialResults results = { {0}, 0 };
	int i;

	// Pass address of struct instead of value
	computeFactorials(&results, NUM_FACTS);
	for (i = 0; i < NUM_FACTS; i++)
	{
		printf("%5d %12d\n", i, results.results[i]);
	}
	return 0;
}