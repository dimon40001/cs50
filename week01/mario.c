#include <cs50.h>
#include <stdio.h>

void printHash(int i);

int main(void)
{
    int height = 0;
    do 
    {
        height = get_int("Height: ");
    } 
    while (height < 1 || height > 8);
    
    for (int i = 1; i <= height; i++) 
    {
        // print every row (4 parts)
        for (int j = 1; j <= height - i; j++) 
        {
            printf(" ");
        }
        printHash(i);
        printf("  ");
        printHash(i);
        printf("\n");
    }
}

void printHash(int i) 
{
    for (int j = 1; j <= i; j++) 
    {
        printf("#");
    }
}
