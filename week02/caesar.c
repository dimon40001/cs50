#include <cs50.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const string USAGE = "Usage: ./caesar key";
    
int main(int argc, string argv[])
{
    if (argc != 2) 
    {
        printf("%s\n", USAGE);
        return 1;
    }
    
    long key = -1;
    key = strtol(argv[1], NULL, 10);
    if (key <= 0) 
    {
        printf("%s\n", USAGE);
        return 1;
    }
    
    string plain = get_string("plaintext: ");
    printf("ciphertext: ");
    
    for (int i = 0; i < strlen(plain); i++) 
    {
        char c = plain[i];
        if (c >= 65 && c <= 90) 
        {
            c = 65 + (c - 65 + key) % 26;
        }    
        if (c >= 97 && c <= 122) 
        {
            c = 97 + (c - 97 + key) % 26;
        }   
        printf("%c", c);
    }
    printf("\n");
}
