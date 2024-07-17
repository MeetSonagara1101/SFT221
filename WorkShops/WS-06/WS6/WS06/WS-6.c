#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stringhelp.h"
#include <string.h>
#include <ctype.h>
#include "log4c.h"

int main(void)
{
	char testStr[] = "This is a\n string with embedded newline characters and \n12345 numbers inside it as well 67890";
	struct StringIndex index = indexString(testStr);
	int i;
	printf("LINES\n");
	for (i = 0; i < index.numLines; i++)
	{
		printUntil(index.str, index.lineStarts[i], '\0'); // CORRECTED CODE
		//printUntil(index.str, index.lineStarts[i], '\n'); // BUG CODE
		printf("\n");
	}
	printf("\nWORDS\n");
	for (i = 0; i < index.numWords; i++)
	{
		printUntilSpace(index.str, index.wordStarts[i]);
		printf("\n");
	}
	printf("\nNUMBERS\n");
	for (i = 0; i < index.numNumbers; i++)
	{
		printUntilSpace(index.str, index.numberStarts[i]);
		printf("\n");
	}

	char errMsg[L4C_ERROR_MSG_MAX + 1] = { 0 };
	struct Log4cStruct log = l4cOpen("log.txt", 0);
	if (l4cCheck(&log, errMsg)) printf("%s\n", errMsg);
	else
	{
		l4cError(&log, "error msg");
		if (l4cCheck(&log, errMsg)) printf("%s\n", errMsg);

		l4cWarning(&log, "warning msg");
		if (l4cCheck(&log, errMsg)) printf("%s\n", errMsg);

		l4cInfo(&log, "info msg");
		if (l4cCheck(&log, errMsg)) printf("%s\n", errMsg);

		l4cPrintf(&log, L4C_INFO, "I am %d years old", 47);
		if (l4cCheck(&log, errMsg)) printf("%s\n", errMsg);

		l4cClose(&log);
	}
	return 0;
}