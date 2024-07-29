// Print a random number from 1 to 6

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // time_t seconds;
    // printf("Seconds since January 1,1970 =%ld\n",time(0));
    int rand_no;
    srand(time(0));
    rand_no = rand() % 6 + 1;
    printf("Random no:%d\n", rand_no);
    return 0;
}