#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%p\n", s);
    printf("%s\n", s);
    printf("%s\n", s+1);
    printf("%s\n", s+2);
}