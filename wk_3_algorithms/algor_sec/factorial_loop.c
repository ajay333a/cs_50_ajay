#include <cs50.h>
#include <stdio.h>

int factorial_loop(int num);

int main(void)
{
    int n = get_int("Type: ");
    printf("%i\n", factorial_loop(n));
}

int factorial_loop(int num)
{
    int fct = num;
    for (int i = num - 1; i >= 1; i--)
    {
       fct *= i ;
    }
    return fct;
}