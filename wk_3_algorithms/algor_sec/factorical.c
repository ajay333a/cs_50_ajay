#include <cs50.h>
#include <stdio.h>

int factorial(int num);

int main(void)
{
    int n = get_int("Type: ");
    printf("%i\n", factorial(n));
}

int factorial(int num)
{
    if ( num == 1)
    {
        return 1;
    }

    return num * factorial(num - 1);
}