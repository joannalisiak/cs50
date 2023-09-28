#include <cs50.h>
#include <stdio.h>

bool check_valid_length(long n);
bool check_valid_checksum(long n);
string check_issuer(long n);

int main(void)
{
    long number = get_long("Credit card number: ");

    bool valid_length = check_valid_length(number);
    // printf("has valid length: %d\n", valid_length);
    if (!valid_length)
    {
        printf("INVALID\n");
        return 0;
    }

    bool valid_checksum = check_valid_checksum(number);
    // printf("has valid checksum: %d\n", valid_checksum);
    if (valid_checksum)
    {
        string issuer = check_issuer(number);
        printf("%s\n", issuer);
    }
    else
    {
        printf("INVALID\n");
    }
}

bool check_valid_length(long n)
{
    int i = 0;
    while (n > 0)
    {
        n /= 10;
        i++;
    }
    if (i == 13 || i == 15 || i == 16)
    {
        return true;
    }
    return false;
}

bool check_valid_checksum(long n)
{
    int sum1 = 0;
    int sum2 = 0;

    while (n > 0)
    {
        // add last digit and strip it
        sum1 += n % 10;
        n /= 10;

        // multiply second to last digit, add its digits and strip ot
        int d1 = (n % 10 * 2) % 10;
        int d2 = (n % 10 * 2) / 10;
        sum2 += d1 + d2;
        n /= 10;
    }

    int checksum = sum1 + sum2;
    if (checksum % 10 == 0)
    {
        return true;
    }
    return false;
}

string check_issuer(long n)
{
    string result = "";

    int i = 0;
    long x = n;
    while (x > 0)
    {
        x /= 10;
        i++;
    }
    // printf("number of digits: %i\n", i);

    long d = n;
    while (d > 100)
    {
        d /= 10;
    }
    // printf("last two digits: %ld\n", d);

    if (i == 15 && d / 10 == 3 && (d % 10 == 4 || d % 10 == 7))
    {
        result = "AMEX";
    }
    if (i == 16 && d / 10 == 5 && (d % 10 > 0 && d % 10 < 6))
    {
        result = "MASTERCARD";
    }
    if ((i == 13 || i == 16) && d / 10 == 4)
    {
        result = "VISA";
    }
    return result;
}
