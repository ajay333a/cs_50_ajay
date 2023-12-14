#include <cs50.h>
#include <stdio.h>
#include <math.h>

int ev_other_dgt(long ccn);
int multiply_add(int last_dgt);
int num_of_dgts(long ccn);
bool amex_valid(long ccn, int length);
bool master_valid(long ccn, int length);
bool visa_valid(long ccn, int length);

int main(void)
{
    long ccn = get_long("Number: ");

    int sum_every_other_digit = ev_other_dgt(ccn);

    int cc_lng = num_of_dgts(ccn);
    bool amex = amex_valid(ccn, cc_lng);
    bool master = master_valid(ccn, cc_lng);
    bool visa = visa_valid(ccn, cc_lng);

    if (sum_every_other_digit % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    else if (amex == true)
    {
        printf("AMEX\n");
    }
    else if (master == true)
    {
        printf("MASTERCARD\n");
    }
    else if (visa == true)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}

int num_of_dgts(long ccn)
{
    int count = 0;
    while (ccn > 0)
    {
        count++;
        ccn /= 10;
    }
    return count;
}

bool amex_valid(long ccn, int length)
{
    int first_two_digits = ccn / pow(10, 13);
    if ((length == 15) && (first_two_digits == 34 || first_two_digits == 37))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool master_valid(long ccn, int length)
{
    int first_two_digits = ccn / pow(10, 14);
    if ((length == 16) && (first_two_digits >= 51 && first_two_digits <= 55))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool visa_valid(long ccn, int length)
{
    if (length == 13)
    {
        int first_dgt = ccn / pow(10, 12);
        if (first_dgt == 4)
        {
            return true;
        }
    }
    else if (length == 16)
    {
        int first_dgt = ccn / pow(10, 15);
        if (first_dgt == 4)
        {
            return true;
        }
    }
    return false;
}

int ev_other_dgt(long ccn)
{
    int total = 0;
    bool alternate_bool = false;
    while (ccn > 0)
    {
        if (alternate_bool == true)
        {
            int lst_dgt = ccn % 10;
            int product = multiply_add(lst_dgt);
            total += product;
        }
        else
        {
            int lst_dgt = ccn % 10;
            total += lst_dgt;
        }
        alternate_bool = !alternate_bool;
        ccn = ccn / 10;
    }
    return total;
}

int multiply_add(int lst_dgt)
{
    int multiply = lst_dgt * 2;
    int sum = 0;
    while (multiply > 0)
    {
        int lst_dgt_multiply = multiply % 10;
        sum += lst_dgt_multiply;
        multiply /= 10;
    }
    return sum;
}
