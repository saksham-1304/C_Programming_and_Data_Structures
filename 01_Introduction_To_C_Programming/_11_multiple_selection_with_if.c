// Multiple Selection With If

#include <stdio.h>
int main()
{
    int day;
    printf("Enter day number\n");
    scanf("%d", &day);
    /*
    if (day == 0)
    {
        printf("Sunday");
    }
    if (day == 1)
    {
        printf("Monday");
    }
    if (day == 2)
    {
        printf("Tuesday");
    }
    if (day == 3)
    {
        printf("Wednesday");
    }
    if (day == 4)
    {
        printf("Thursday");
    }
    if (day == 5)
    {
        printf("Friday");
    }
    if (day == 6)
    {
        printf("Saturday");
    }
    if (day < 0 || day > 6)
    {
        printf("Error-invalid day \n");
    }
    */

    if (day == 0)
    {
        printf("Sunday");
    }
    else if (day == 1)
    {
        printf("Monday");
    }
    else if (day == 2)
    {
        printf("Tuesday");
    }
    else if (day == 3)
    {
        printf("Wednesday");
    }
    else if (day == 4)
    {
        printf("Thursday");
    }
    else if (day == 5)
    {
        printf("Friday");
    }
    else if (day == 6)
    {
        printf("Saturday");
    }
    else if (day < 0 || day > 6)
    {
        printf("Error-invalid day \n");
    }

    return 0;
}
