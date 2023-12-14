#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What's your name? ");
    int age = get_int("What's your age? ");
    string number = get_string("What's your number? ");

    printf("Name is %s , Ahe is %i and number is %s.\n", name, age, number);

    char confirm  = get_char("y/n? ");

    if (confirm == 'y')
    {
        printf("Details saved\n");
    }
    else if (confirm == 'n')
    {
        printf("Details not saved\n");
    }
}

