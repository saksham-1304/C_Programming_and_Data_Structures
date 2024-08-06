// Create Union

#include <stdio.h>
union MyUnion
{
    char c;
    int i;
    float f;
    double d;
};
int main()
{
    union MyUnion u;
    u.i = 79;

    printf("%c\n", u.c);
    printf("%d\n", u.i);
    printf("%f\n", u.f);
    printf("%lf\n", u.d);
}