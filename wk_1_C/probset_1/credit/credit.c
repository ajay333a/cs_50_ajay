#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

// functions written
int sum_of_alt_num(long ccn);
int prdt_add(int last_dgt);
bool hans_reminder(int hans_sum);
int ccn_length(long ccn);
int frst_two_dgts(long ccn, int ccn_len);
string company_search(int ccn_len, int two_dgts);


int main(void)
{
    // Prompting for a long input
    long ccn;
    ccn = get_long("Number: ");
    // Hans peters formula check
    int hans_sum = sum_of_alt_num(ccn);
    // obtaining length of credit card number
    int ccn_len = ccn_length(ccn);
    // obtaing first two digits of credit card
    int two_dgts = frst_two_dgts(ccn, ccn_len);
    // assigning comapany after searching the company
    string company = company_search(ccn_len, two_dgts);
    // obtaining output
    if (hans_reminder(hans_sum) == false)
    {
        printf("INVALID\n");
        return 0;
    }
    else
    {
        printf("%s\n", company);
    }
}

// adding sum of alternate first digits by
int sum_of_alt_num(long ccn)
{
    // creating a variable to add sum all digits in odd place;
    int odd_sum = 0;
    int even_sum = 0;
    bool alt_bool = false;
    while (ccn > 0)
    {
        if (alt_bool == false)
        {
            int lst_dgt = ccn % 10;
            odd_sum += lst_dgt;
        }
        else
        {
            int lst_dgt = ccn % 10;
            int pd_lst_dgt = prdt_add(lst_dgt);
            even_sum += pd_lst_dgt;
        }
        alt_bool = !alt_bool;
        ccn /= 10;
    }
    int sum = odd_sum + even_sum;
    return sum;
}

// mutiplying and adding every even digit form left with two and adding if the number is greater than 9
int prdt_add(int last_dgt)
{
    int pd_2 = last_dgt * 2;
    int pd_sum = 0;
    while (pd_2 > 0)
    {
        int lst_sum = pd_2 % 10;
        pd_sum += lst_sum;
        pd_2 /= 10;
    }
    return pd_sum;
}

// checking for hans_reminder i.e., 0
bool hans_reminder(int hans_sum)
{
    bool reminder = (hans_sum % 10 == 0) ? true : false;
    return  reminder;
}

// Calculating number of digits of credit card
int ccn_length(long ccn)
{
    int ccn_len = 0;
    while (ccn > 0)
    {
        ccn /= 10;
        ccn_len++;
    }
    return ccn_len;
}

// checking for first two digits in the card
int frst_two_dgts(long ccn, int ccn_len)
{
    int y = ccn_len - 2;
    int dgts = ccn / pow(10, y);
    return dgts;
}

// checking for correct credit card brand
string company_search(int ccn_len, int two_dgts)
{
    string company;
    if ((ccn_len == 15) && (two_dgts == 34 || two_dgts == 37))
    {
        company = "AMEX";
    }
    else if ((ccn_len == 16) && (two_dgts >= 51 && two_dgts <= 55))
    {
        company = "MASTERCARD";
    }
    else if ((ccn_len == 13 || ccn_len == 16) && (two_dgts >= 40 && two_dgts <= 49))
    {
        company = "VISA";
    }
    else
    {
        company = "INVALID";
    }
    return company;
}

