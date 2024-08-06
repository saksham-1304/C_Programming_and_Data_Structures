// Nested Union

#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char *name;
    int cal;
} Fruit;

typedef struct
{
    char *name;
    int cal;
    int time; // Cooking time
} Vegetable;

typedef union
{
    Fruit frt;
    Vegetable veg;

} Fruit_or_Veg;

Fruit_or_Veg f_v_1, f_v_2;
int main()
{
    f_v_1.frt.name = (char *)malloc(10);
    f_v_1.frt.name = "Apple";
    f_v_1.frt.cal = 10;

    f_v_2.veg.name = (char *)malloc(10);
    f_v_2.veg.name = "Potato";
    f_v_2.veg.cal = 20;
    f_v_2.veg.time = 15;

    printf("Fruit name %s cal %d\n", f_v_1.frt.name, f_v_1.frt.cal);
    printf("Veg name %s cal %d time %d\n", f_v_2.veg.name, f_v_2.veg.cal, f_v_2.veg.time);
}
