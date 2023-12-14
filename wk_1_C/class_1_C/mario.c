#include <stdio.h>
#include <cs50.h>

int get_size(void);
void print_bricks(int size);

int main(void)
{
    // Get size of the grid
    int n = get_size();

    // Print grid of grids
    print_bricks(n);
}

int get_size(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1);
    return n;
}

void print_bricks(int size)
{
    for (int i = 0; i < size; i++)
    {
       for (int j = 0; j < size; j++)
       {
            printf("#");
       }
       printf("\n");
    }
}