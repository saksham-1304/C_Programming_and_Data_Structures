// String Conversion Functions

#include <stdio.h>
#include <stdlib.h>
int main()
{
    const char *s = "3.14159";
    double dnumber = atof(s);
    int inumber = atoi(s);
    long lnumber = atol(s);
    printf("The parsed double value is:%f\n", dnumber);
    printf("The parsed int value is:%d\n", inumber);
    printf("The parsed long value is:%ld\n", lnumber);
    return 0;
}
