#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

void concat(char dest[], const char src[])
{
    int dp = 0, sp = 0;
    if (dest != NULL)
    {
        for (dp = 0; dest[dp] != '\0'; dp++);
        if (src != NULL)
        {
            for (sp = 0; src[sp] != '\0'; sp++)
            {
                dest[dp++] = src[sp];
            }
            dest[dp] = '\0';
        }
    }
}

int main() {
    void concat(char dest[], const char src[]);
    return 0;
};
