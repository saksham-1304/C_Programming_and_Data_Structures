// Search For Character From End In String

#include <stdio.h>
#include <string.h>
int main()
{
    char mystr[50] = "I'm an example of function strrchr";
    printf("%s", strrchr(mystr, 'f'));
    return 0;
}