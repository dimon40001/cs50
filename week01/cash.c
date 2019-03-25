#include <cs50.h>
#include <stdio.h>
#include <math.h>

int countCoins(int cents, int coinValue);

int main()
{
    float cash;
    do
    {
        cash = get_float("Change owed: ");
    }
    while (cash < 0);
    
    int cents = round(cash * 100);
    int coins = 0;
    
    int c = 0;
    c = countCoins(cents, 25);
    coins += c;
    cents -= c * 25;
    c = countCoins(cents, 10);
    coins += c;
    cents -= c * 10;
    c = countCoins(cents, 5);
    coins += c;
    cents -= c * 5;
    coins += cents;
    
    printf("%d\n", coins);
}

int countCoins(int cents, int coinValue)
{
    int coins = 0;
    while (cents / coinValue > 0)
    {
        coins++;
        cents -= coinValue;
    }
    
    return coins;
}
