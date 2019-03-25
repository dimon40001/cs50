#include <cs50.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getNormal(long value);
int getDouble(long value);

int main()
{
    string card;
    long number;
    do
    {
        card = get_string("Number: ");
        number = strtol(card, NULL, 10);

    }
    while (number <= 0);
    
    // check valid
    int doubled = getDouble(number);
    int normal = getNormal(number);
    
    if ((doubled + normal) % 10 != 0)
    {
        printf("INVALID\n");
        exit(0);
    }
 
    int len = strlen(card);
    // printf("%d\n", len);
    // detect type
    if (card[0] == '3' && (card[1] == '4' || card[1] == '7')) 
    {
        printf("AMEX\n");
    } 
    else if (card[0] == '4' && (len == 13 || len == 16))
    {
        printf("VISA\n");
    }
    else if (card[0] == '5') 
    {
        if (
            card[1] == '1' ||
            card[1] == '2' ||
            card[1] == '3' ||
            card[1] == '4' ||
            card[1] == '5' 
           )
        {
            printf("MASTERCARD\n");    
        } 
        else
        {
            printf("INVALID\n");
        }
        
    } 
    else
    {
        printf("INVALID\n");
    }
}

int getNormal(long value)
{
    int sum = 0;
    while (value != 0)
    {
        sum += value % 10;
        value = value / 100;
    }
    return sum;
}

int getDouble(long value)
{
    int sum = 0;
    value = value / 10;
    while (value != 0)
    {
        int digit = value % 10;
        if (digit * 2 > 9) 
        {
            sum += 1 + (digit * 2) % 10;    
        } 
        else
        {
            sum += digit * 2; 
        }
        value = value / 100;
    }
    return sum;
}
