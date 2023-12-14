// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string word);

int main(int argc, string argv[])
{
    if (argc == 2) // checking for number of cmd line arguments
    {
        string new_word = replace(argv[1]);
        printf("%s\n", new_word);
    }
    else // printing error if cmd-line-arg is not 2 words
    {
        printf("Command line arguments are not ideal.\n");
        return 1;
    }
}

string replace(string word)
{
    int len_str = strlen(word);
    for (int i = 0;  i < len_str; i++)
    {
        switch (word[i]) // using switch function to replace vowels
        {
            case 'a':
                word[i] = '6';
                break;
            case 'e':
                word[i] = '3';
                break;
            case 'i':
                word[i] = '1';
                break;
            case 'o':
                word[i] = '0';
                break;
            default:
                break;
        }
    }
    return word;
}

