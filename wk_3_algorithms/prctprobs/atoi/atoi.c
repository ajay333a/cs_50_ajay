#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    int n = strlen(input);

    if (n <= 1)
    {
        return input[0] - '0';
    }

    char lst_dgt = input[n - 1]; // removing end string
    int converted_lst_dgt = lst_dgt - '0'; //converting last string into int
    input[n - 1] = '\0'; // replacing last digit with empty string

    return converted_lst_dgt + convert(input) * 10;
}