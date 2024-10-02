#include<stdio.h>
int stringToInt(char *str)
{
    int num=0;
    while(*str)
    {
        num=num*10+(*str-'0');
        str++;
    }
    return num;
}

int main(int argc,char*argv[])
{
    int sum=0;
    for(int i=1;i<argc;i++)
    {
       sum+=stringToInt(argv[i]);

    }
    printf("Sum of %d numbers is %d\n",argc-1,sum);
    return 0; 
}