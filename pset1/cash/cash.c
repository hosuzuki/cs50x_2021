#include <cs50.h>
#include <stdio.h>
#include <math.h>
int main(void)
{
    float change;
    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0.009);
    int cent = round(change * 100);
    int changeowed = 0;
    while (cent >= 25)
    {
        cent = cent - 25;
        changeowed++;
    }
    while (cent >= 10)
    {
        cent = cent - 10;
        changeowed++;
    }
    while (cent >= 5)
    {
        cent = cent - 5;
        changeowed++;
    }
    while (cent >= 1)
    {
        cent = cent - 1;
        changeowed++;
    }
    printf("%i\n", changeowed);
}