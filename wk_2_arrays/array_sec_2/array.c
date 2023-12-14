#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // promting for input i.e, size
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n <= 0);

    // creating array of size n
    int array[n];
    // value of first element
    printf("%i\n", array[0] = 1);
    // creating next elements twice the previous
    for (int i = 1; i < n; i++)
    {
        array[i] =  2 * array[i - 1];
        printf("%i\n", array[i]);
    }
}