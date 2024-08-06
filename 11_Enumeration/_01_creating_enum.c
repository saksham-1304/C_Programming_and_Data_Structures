// Creating enum

#include <stdio.h>
enum Days
{
    Sunday,    // 0
    Monday,    // 1
    Tuesday,   // 2
    Wednesday, // 3
    Thursday,  // 4
    Friday,    // 5
    Saturday   // 6
};

int main()
{
    enum Days d1, d2;
    d1 = Wednesday;
    printf("%d", d1);
    enum Days day = Sunday;
    int today;
    char input[10];

    printf("Enter today's day (0 for Sunday, 1 for Monday, ..., 6 for Saturday): \n");
    if (scanf("%d", &today) != 1)
    {
        // Clear invalid input
        scanf("%s", input);
        printf("Invalid input\n");
        return 1;
    }

    switch (today)
    {
    case Sunday:
        printf("Sunday");
        break;

    case Monday:
        printf("Monday");
        break;
    case Tuesday:
        printf("Tuesday");
        break;
    case Wednesday:
        printf("Wednesday");
        break;
    case Thursday:
        printf("Thursday");
        break;
    case Friday:
        printf("Friday");
        break;
    case Saturday:
        printf("Saturday");
        break;
    default:
        printf("Invalid input");
        break;
    }
}