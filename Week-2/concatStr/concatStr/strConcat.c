#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

void concat(int dest[], const char src[])
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
    int dest[50] = "";
    const char src[] = "";

    concat(dest, src);

    printf("Concatenated string : % s\n", dest);

    return 0;
};