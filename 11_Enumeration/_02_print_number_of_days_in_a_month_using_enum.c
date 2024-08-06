// Write a program to return the number of days in a month using enum

#include <stdio.h>
#include <stdlib.h>
enum Months
{
    January,   // 0
    February,  // 1
    March,     // 2
    April,     // 3
    May,       // 4
    June,      // 5
    July,      // 6
    August,    // 7
    September, // 8
    October,   // 9
    November,  // 10
    December,  // 11
};
int DaysInMonth(enum Months month)
{
    switch (month)
    {
    case April:
    case June:
    case September:
    case November:
        return 30;
        break;
    case February:
        return 28; // Assuming it's not a leap year
        break;
    default:
        return 31;
        break;
    }
}
int main()
{
    int month;
    printf("Enter the month (as a number ,0-11):\n");
    scanf("%d", &month);
    if (month < January || month > December)
    {
        fprintf(stderr, "Invalid month number.\n");
        exit(1);
    }

    int numDays = DaysInMonth(month);
    printf("Number of days in the selected month: %d\n", numDays);
    return 0;
}