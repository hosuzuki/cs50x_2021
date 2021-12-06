#include <cs50.h>
#include <stdio.h>
int main(void)
{
    long n = get_long("Number: ");
    int i = 0;
    long x = n;
    while (x > 0)
    {
        x = x / 10;
        i++;
    }
    if (i != 13 && i != 15 && i != 16)
    {
        printf("INVALID\n");
        return 0;
    }
    long y = n;
    int sum1 = 0;
    int sum2 = 0;
    int d1;
    int d2;
    int mod1;
    int mod2;
    int total = 0;
    do
    {
        mod1 = y % 10;
        y = y / 10;
        sum1 = sum1 + mod1;

        mod2 = y % 10;
        y = y / 10;
        mod2 = mod2 * 2;
        d1 = mod2 % 10;
        d2 = mod2 / 10;
        sum2 = sum2 + d1 + d2;
    }
    while (y > 0);
    total = sum1 + sum2;
    int f = total % 10;
    if (f != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    long s = n;
    do 
    {
        s = s / 10;
    }
    while (s > 100);
    if ((s / 10 == 5) && (0 < s % 10) && (s % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
    else if ((s / 10 == 3) && (s % 10 == 4 || s % 10 == 7))
    {
        printf("AMEX\n");
    }
    else if (s / 10 == 4)
    {
        printf("VISA\n");
    }
    else 
    {
        printf("INVALID\n");    
    }
}


