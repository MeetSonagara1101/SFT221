#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 20



int split(char line[], char words[][MAX_WORD_LEN + 1], int maxWords)
{
    char ch;
    char buf[MAX_WORD_LEN + 1] = { 0 };
    int lp = 0, bp = 0, wp = 0, result = 0;

    ch = line[lp];
    while (ch != '\0' && result >= 0)
    {
        while (ch != '\0' && (ch == ' ' || ch == '\t')) ch = line[++lp];

        bp = 0;
        while (ch != '\0' && !(ch == ' ' || ch == '\t'))
        {
            buf[bp++] = ch;
            ch = line[++lp];
        }
        if (bp > 0)
        {
            buf[bp] = '\0';
            if (wp >= maxWords)
            {
                result = -1;
            }
            else
            {
                strcpy(words[wp++], buf);
            }
        }
    }
    result = (result < 0) ? result : wp;
    return result;
}

int main(void)
{
    char line[] = { "" };
    char words[10][MAX_WORD_LEN + 1] = { 0 };
    int nwords, i;

    nwords = split(line, words, 10);

    for (i = 0; i < nwords; i++)
    {
        printf("%s\n", words[i]);
    }

    return 0;
}