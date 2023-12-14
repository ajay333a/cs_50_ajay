// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}


bool valid(string password)
{
    int pwd_len = strlen(password);

    bool upper = false;
    bool lower = false;
    bool number = false;
    bool symbol = false;

    for (int i = 0; i < pwd_len; i++)
    {
        if (isupper(password[i])) // checking for upper case letters
        {
            upper = true;
        }
        if (islower(password[i])) // checking for lower case letters
        {
            lower = true;
        }
        if (isdigit(password[i])) // checking for numbers
        {
            number = true;
        }
        if (ispunct(password[i])) // checking for symbols
        {
            symbol = true;
        }
    }

    // returning false if one of the conditions failed
    if (upper == false || lower == false || number == false || symbol == false)
    {
        return false;
    }
    else
    {
        return true;
    }
}
