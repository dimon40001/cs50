#include <cs50.h>

#include <stdio.h>
#include <string.h>
#include <crypt.h>
#include <unistd.h>

const int MAX_SIZE = 10;
const string USAGE = "Usage: ./crack hash";

char *getPassword(int i);

int main(int argc, string argv[])
{
    
    // char *crypt(const char *key, const char *salt);
    // string input = get_string("String to code: ");
    // string result = crypt(input, "50");
    // printf("%s\n", result);
    
    if (argc != 2) 
    {
        printf("%s\n", USAGE);
        return 1;
    }
    
    string decode = argv[1];
    
    char salt[3];
    strncpy(salt, decode, 2);
    salt[2] = '\0'; 
    
    for (int i = 1; true; i++) 
    {
        string password = getPassword(i);
        string hash = crypt(password, salt);

        if (strcmp(hash, decode) == 0) 
        {
            // password has been found
            printf("%s\n", password);
            return 0;
        }
    }
}

char *getPassword(int i)
{
    string searchItems = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

    int size = strlen(searchItems);
    int k = i;
    int places = 0;
    
    while (k != 0)
    {
        places++;
        k /= size;
        
    }
    int initialPlaces = places;
    char *result;
    result = (char *) malloc(10 * sizeof(char));
    
    k = i;
    while (k != 0)
    {
        result[places - 1] = searchItems[k % size];
        places--;
        k = k / size;
    }
    
    return result;
}
