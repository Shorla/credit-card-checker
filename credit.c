#include <stdio.h>
long check_digit(int credit_card_length);
int main(void)
{   
    

    long credit_card = 4003600000000014L;
    int credit_card_length = 0;

    while (credit_card != 0)
    {
        credit_card = credit_card/10;
        credit_card_length++;
    }

     printf("A - %ld/n", check_digit(credit_card_length));
}
//get the sum

long check_digit(int credit_card_length)
{
    long divisor = 10;

    for(int i = 0; i < credit_card_length - 2; i++)
    {
        divisor = divisor * 10;
    }

    return divisor;
}