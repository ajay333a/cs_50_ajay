#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    // Geting minimum range
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);
    // Getting maximum range
    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);
    // printing the primes after checking
    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}
// checking for primes
bool prime(int number)
{
    if (number < 2) // Not printing 1 as it is not prime
    {
        return false;
    }
    if (number == 2 || number == 3) // Printing 2 and 3
    {
        return true;
    }
    for (int j = 2; j < number; j++) // looping over all numbers to check for primes
    {
        if (number % j == 0)
        {
            return false;
        }
    }
    return true;
}

