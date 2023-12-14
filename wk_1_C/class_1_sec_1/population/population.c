#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // get start population
    int start_pop;
    do
    {
        start_pop = get_int("Start Population: ");
    }
    while (start_pop < 9);

    // get end_pop
    int end_pop;
    do
    {
        end_pop = get_int("End Population: ");
    }
    while (start_pop > end_pop);

    // How many years will it take to reach end_pop
    int years = 0;
    // Every year 1/3 llamas are added and 1/4 llamas are subtracted
    while (start_pop < end_pop)
    {
        start_pop += (start_pop / 3) - (start_pop / 4);
        years++;
    }
    printf("Years: %i\n", years);
}

