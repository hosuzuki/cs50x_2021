#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//get commandline
int main(int argc, string argv[])
{
//validate commandline
    //if no entry - Usage: ./substitution KEY
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
    //if fewer - Key must contain 26 characters.
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    //if non letter - Key must only contain alphabetic characters.
    else
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (! isalpha(argv[1][i]))
            {
                printf("Key must only contain alphabetic characters.\n");
                return 1;
            }
            //if a letter repeated - Key must not contain repeated characters.
            for (int j = i + 1, m = strlen(argv[1]); j < m; j++)
            {
                if (toupper(argv[1][i]) == toupper(argv[1][j]))
                {
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }
            }
        }
//get plaintext:
        string p = get_string("plaintext: ");
//encipher
//print ciphertext
        printf("ciphertext: ");
        for (int i = 0, n = strlen(p); i < n; i++)
        {
            if (isupper(p[i]))
            {
                int upper = p[i] - 'A';
                char u = toupper(argv[1][upper]);
                printf("%c", u);
            }
            else if (islower(p[i]))
            {
                int lower = p[i] - 'a';
                char l = tolower(argv[1][lower]);
                printf("%c", l);
            }
            else
            {
                printf("%c", p[i]);
            }
        }
        printf("\n");
    }
}