// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1); // prompting input until user provides a positive number

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i); // prompting for the numbers
    }

    printf("The max value is %i.\n", max(arr, n));
}

// FInding the max value
int max(int array[], int n)
{
    int max_num = array[0];

    for (int i = 0; i < n; i++)
    {
        if (array[i] > max_num)
        {
            max_num = array[i]; // assining max value to max_num
        }
    }
    return max_num;
}
