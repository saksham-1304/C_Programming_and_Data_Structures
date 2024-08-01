// Search For Character From Beginning In String

#include <stdio.h>
#include <string.h>
int main()
{
    char mystr[40] = "I'm an example of function strchr";
    printf("%s", strchr(mystr, 'f'));
    return 0;
}