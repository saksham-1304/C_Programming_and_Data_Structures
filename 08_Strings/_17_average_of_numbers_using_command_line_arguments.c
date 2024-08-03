// Command Line

// Write a program to compute average of numbers given as command line arguments

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    float sum = 0;
    int i;
    for (int i = 1; i < argc; i++)
    {
        sum += atof(argv[i]);
    }
    printf("Average %f", sum / (argc - 1));
}