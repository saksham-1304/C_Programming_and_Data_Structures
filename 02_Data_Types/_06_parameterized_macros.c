// Parameterized Macros

#include <stdio.h>
#define cir(r) 3.14*r*r
int main() 
{
    int radius;
    float area;
    scanf("%d", &radius);
    area = cir(radius);
    printf("Area:%f\n", area);
}