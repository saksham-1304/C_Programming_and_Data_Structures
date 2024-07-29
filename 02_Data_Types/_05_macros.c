// Macros

#include <stdio.h>
#define PI 3.14
int main()
{
    printf("%f\n", PI);
    printf("%s\n", __TIME__);
    printf("%s\n", __DATE__);
    printf("%d\n", __LINE__);
    printf("%d\n", __FILE__);
    printf("%s\n", __STDC__);
}