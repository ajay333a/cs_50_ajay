#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    //get string from user
    string message = get_string("Message: ");

    int n = BITS_IN_BYTE; // assing byte length;
    int bit[BITS_IN_BYTE]; //vreating bit array of len 8

    for (int i = 0, len = strlen(message); i < len; i++)
    {
        char byte = message[i]; // assining alphabet to byte
        int alpha = byte; // assining byte to int
        int rmdr; // creating an empty rmdr
        for (int j = 0; j < n; j++)
        {
            rmdr = alpha % 2;
            alpha /= 2;
            bit[j] = rmdr; //creating bit[j] byte
        }

        for (int k = n - 1; k >= 0; k--) // creating loop to print bulbs in correct order
        {
            print_bulb(bit[k]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
