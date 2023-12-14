#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2) // making sure arg len is equal to 2.
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    // opening and assigning input file
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open the file\n");
        return 2;
    }

    // declaring a char of size 512 for storage
    unsigned char buffer[512];

    int count_image = 0;

    FILE *output = NULL;

    char *file = malloc(8 * sizeof(char));

    while (fread(buffer, sizeof(char), 512, input) != 0)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (output != NULL) //close output if jpeg was written before;
            {
                fclose(output);
            }
            // naming the output image
            sprintf(file, "%.3i.jpg", count_image);

            // opening file for writing
            output = fopen(file, "w");

            // counting the images
            count_image++;
        }

        if (output != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output);
        }
    }

    free(file); //freeing the memory of file

    if (output != NULL)
    {
        fclose(output); //closing the output file
    }

    fclose(input); //closing input file

    return 0;
}
