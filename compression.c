#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RLEN 50

//Returns the Run Length Encoded string for the 
   source string src
char* encode(char* src)
{
    int rLen;
    char count[MAX_RLEN];
    int len = strlen(src);

    char* dest = (char*)malloc(sizeof(char) * (len * 2 + 1));

    int i, j = 0, k;

    // traverse the input string one by one 
    for (i = 0; i < len; i++) {

        //Copy the first occurrence of the new character 
        dest[j++] = src[i];

        //Count the number of occurrences of the new character
        rLen = 1;
        while (i + 1 < len && src[i] == src[i + 1]) {
            rLen++;
            i++;
        }

        sprintf(count, "%d", rLen);

        for (k = 0; *(count + k); k++, j++) {
            dest[j] = count[k];
        }
    }

    //terminate the destination string 
    dest[j] = '\0';
    return dest;
}

int main()
{
    char str[] = "wwwwaaadexxxxywww";
    char* res = encode(str);
    printf("%s", res);
    getchar();
}
