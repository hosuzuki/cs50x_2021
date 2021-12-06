#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //get one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int key = atoi(argv[1]);
    string plain = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        if (isupper(plain[i]))
        {
            int m = plain[i];
            int u = (m - 'A' + key) % 26;
            printf("%c", u + 'A');
        }
        else if (islower(plain[i]))
        {
            int m = plain[i];
            int u = (m - 'a' + key) % 26;
            printf("%c", u + 'a');
        }
        else
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
}