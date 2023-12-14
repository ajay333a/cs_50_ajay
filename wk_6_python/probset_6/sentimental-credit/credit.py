from cs50 import get_int


def main():
    ccn = int(input("Number: "))  # getting credit card number

    hans_sum = sum_alt_num(ccn)   # calculating Hans Sum

    ccn_len = len(str(ccn))  # getting length of card number

    two_dgts = fst_two_dgts(ccn)  # geting first two digits of the card number

    company = search_company(ccn_len, two_dgts)  # searching for company based on card length and first two digits

    if hans_sum % 10 != 0:  # checking if hans
        print("INVALID")
    else:
        print(company)


def sum_alt_num(ccn):  # getting the sum of alternate numbers
    odd_sum = 0
    even_sum = 0
    alt = False
    ccn_len = len(str(ccn))

    while ccn > 0:
        if alt == False:
            lst_dgt = ccn % 10
            odd_sum += lst_dgt
        else:
            lst_dgt = ccn % 10
            pd_lst_dgt = prdt_add(lst_dgt)
            even_sum += pd_lst_dgt
        alt = not (alt)
        ccn //= 10
    ttl_sum = odd_sum + even_sum
    return ttl_sum


def prdt_add(lst_dgt):  # getting sum of product of numbers
    pd_2 = lst_dgt * 2
    pd_sum = 0
    while pd_2 > 0:
        lst_sum = pd_2 % 10
        pd_sum += lst_sum
        pd_2 //= 10
    return pd_sum


def fst_two_dgts(ccn):  # getting length of first two digits
    ccn = str(ccn)
    nums = int(ccn[0] + ccn[1])
    return nums


def search_company(ccn_len, two_dgts):  # Finding the company name

    if ccn_len == 15 and (two_dgts == 34 or two_dgts == 37):
        company = "AMEX"
    elif ccn_len == 16 and 51 <= two_dgts <= 55:
        company = "MASTERCARD"
    elif ccn_len == 13 or (ccn_len == 16 and two_dgts // 10 == 4):
        company = "VISA"
    else:
        company = "INVALID"
    return company


main()
