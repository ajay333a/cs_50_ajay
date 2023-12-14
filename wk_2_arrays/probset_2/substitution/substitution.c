#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_alpha(string s);
bool words_repeated(string s);
void cipher_text(string text, string key);

int main(int argc, string argv[])
{

    // checking for correct number of arguments as input
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int arg_len = strlen(argv[1]); // finding length if argv[1]
    if (arg_len != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    if (!only_alpha(argv[1]))
    {
        printf("Key should only contain alphabets\n"); //finding if key only contains alphabets
        return 1;
    }
    else if (!words_repeated(argv[1]))
    {
        printf("Alphabet in key repeated twice\n"); // finding if any alphabet repeated twice
        return 1;
    }

    // Prompt user for input text
    string text = get_string("plaintext: ");
    printf("ciphertext: ");
    cipher_text(text, argv[1]); //implementing chiper on the text
}

bool only_alpha(string key)
{

    int n = strlen(key);

    for (int i = 0; i < n; i++)
    {
        if (!isalpha(key[i])) // looping through key and chechking if every character is an alphabet
        {
            return false;
        }
    }
    return true;
}

bool words_repeated(string key) // looping through and checking if any character repeated twice
{
    string s = key;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        s[i] = tolower(s[i]); //converting all alphabets to lowercase

        for (int j = i + 1; j < n; j++)
        {
            s[j] = tolower(s[j]); //converting all alphabets to lowercase and then checking for duplicates
            if (s[i] == s[j])
            {
                return false;
            }
        }
    }
    return true;
}

void cipher_text(string text, string key)
{
    int text_len = strlen(text);
    for (int i = 0; i < text_len; i++)
    {
        if (isupper(text[i]))
        {
            char lt = toupper(key[text[i] - 'A']); // encoding upper caseletters
            printf("%c", lt);
        }
        else if (islower(text[i]))
        {
            char lt = tolower(key[text[i] - 'a']); // encoding lower caseletters
            printf("%c", lt);
        }
        else
        {
            printf("%c", text[i]); //not encoding if the character is not an alphabet
        }
    }
    printf("\n");
}