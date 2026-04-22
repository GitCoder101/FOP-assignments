// assignment18.c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], rev[100];
    int i, len;

    printf("Enter string: ");
    scanf("%s", str1);

    printf("Enter another string: ");
    scanf("%s", str2);

    len = strlen(str1);
    printf("Length = %d\n", len);

    for(i=0;i<len;i++)
        rev[i] = str1[len-i-1];
    rev[len] = '\0';

    printf("Reversed = %s\n", rev);

    if(strcmp(str1, rev)==0)
        printf("Palindrome\n");

    if(strcmp(str1, str2)==0)
        printf("Strings are equal\n");
    else
        printf("Not equal\n");

    if(strstr(str1, str2)!=NULL)
        printf("Substring found\n");

    return 0;
}