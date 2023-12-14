#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height, row, column;
    do //prompt user for input between 1 and 8 @
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // looping through rows to print columns
    for (row = 0; row < height; row++)
    {
        // printing spaces before printing #
        for (column = 0; column < height - (row + 1); column++)
        {
            printf(" ");
        }

        for (column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("\n");
    }
}

