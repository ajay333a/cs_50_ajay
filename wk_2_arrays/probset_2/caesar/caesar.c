#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
void rotate(char c, int n);

int main(int argc, string argv[])
{
    // checking for correct number of arguments as input
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (!(only_digits(argv[1])))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]); // converting string to integer

    // geting the string for converstion
    string text = get_string("plaintext: ");

    int str_len = strlen(text);
    printf("ciphertext: ");

    for (int j = 0; j < str_len; j++)
    {
        rotate(text[j], key);
    }
    printf("\n");
}

bool only_digits(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++) // iterating through argv[1] to check for alphas
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

void rotate(char c, int k)
{
    if (isupper(c))
    {
        char cipher = (((c - 'A') + k) % 26) + 65; // applying formula if upper
        printf("%c", cipher);
    }
    else if (islower(c))
    {
        char cipher = (((c - 'a') + k) % 26) + 97; //applying formula if lower
        printf("%c", cipher);
    }
    else
    {
        char cipher = c;
        printf("%c", cipher); // printing same character if not alphabet
    }

}