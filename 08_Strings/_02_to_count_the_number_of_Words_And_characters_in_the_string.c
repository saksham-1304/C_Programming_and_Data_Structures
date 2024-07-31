// Write a function to count th number of characters and words in a string{
#include <stdio.h>
void count_words(char const *p)
{
    int words = 1, characters = 0;
    while (*p != '\0')
    {
        if (isspace(*p))
        {
            p++;
            words++;
        }
        else
        {
            characters++;
            p++;
        }
    }
    printf("Words=%d\t Characters =%d\n", words, characters);
}