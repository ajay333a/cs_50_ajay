#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // geting word from user
    string word = get_string("Word: ");

    int n = strlen(word);
    int wrd_num[n];
    for (int i = 0; i < n; i++)
    {
        if ((word[i] - word[i - 1]) < 0 )
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
}

