#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    } while (n < 1 || n > 8);

    // for each row
    for (int i = 0; i < n; i++)
    {

        // print n-1 spaces for the left side
        for (int j = 1; j < n - i; j++)
        {
            printf(" ");
        }

        // print i+1 hashes for the left side
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }

        // print 2 spaces in the middle
        printf("  ");

        // print i+1 hashes for the right side
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }

        // move to next row
        printf("\n");
    }
}