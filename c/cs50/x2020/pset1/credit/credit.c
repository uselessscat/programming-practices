#include <stdio.h>
#include <cs50.h>

bool isvalid(long);

int main()
{
    long ccnumber = get_long("Number: ");

    // checksum is valid?
    if (!isvalid(ccnumber))
    {
        printf("INVALID\n");

        return 0;
    }

    // check first 2 digits to be 34 or 37
    // i think i can improve this part :C
    if (ccnumber / 10000000000000 == 34 || ccnumber / 10000000000000 == 37)
    {
        printf("AMEX\n");
    }
    else if (ccnumber / 1000000000000 == 4 || ccnumber / 1000000000000000 == 4)
    {
        printf("VISA\n");
    }
    else if (ccnumber / 100000000000000 >= 51 && ccnumber / 100000000000000 <= 55)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

bool isvalid(long ccnumber)
{
    // accumulators of digits
    int pairdigitsum = 0, evendigitsum = 0, aux;

    do
    {
        // get the first digit
        evendigitsum += ccnumber % 10;

        // divide by 10 to displace digits
        ccnumber /= 10;

        // i use an aux to avoid double calculation
        // digit * 2
        aux = (ccnumber % 10) * 2;

        // then divides and uses modulo to sum digits, max number is 9 * 2 == 18
        pairdigitsum += aux / 10 + aux % 10;

        // displace digits until no more digits are available (ccnumber == 0)
        ccnumber /= 10;
    }
    while (ccnumber > 0);

    // get the last digit of the sum, must be 0 to be valid
    return (evendigitsum + pairdigitsum) % 10 == 0;
}