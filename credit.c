#include <cs50.h>
#include <stdio.h>
long get_number(void);
int calculate_credit_card_luhn_sum(long credit_card);
int check_length(long credit_card);
long check_digit(int credit_card_length);
int main(void)
{
    //function prototype
    long credit_card = get_number();
    int sum = calculate_credit_card_luhn_sum(credit_card);
    int credit_card_length = check_length(credit_card);
    long divisor = check_digit(credit_card_length);
    string card_type;

    //get the digits
    long first_digit = credit_card / divisor;
    int first_two_digit = credit_card / (divisor / 10);

    //check for card type
    if (sum % 10 == 0)
    {
        if (first_digit == 4 && (credit_card_length == 13 || credit_card_length == 16))
        {
            card_type = "VISA";
        }
        else if ((first_two_digit == 34 || first_two_digit == 37) && credit_card_length == 15)
        {
            card_type = "AMEX";
        }
        else if ((50 < first_two_digit && first_two_digit < 56) && credit_card_length == 16)
        {
            card_type = "MASTERCARD";
        }
        else
        {
            card_type = "INVALID";
        }
    }
    else
    {
        card_type = "INVALID";
    }

    //print card_type
    printf("%s\n", card_type);
}
//prompt user input
long get_number(void)
{
    long credit_card;
    credit_card = get_long("Number: ");
    return credit_card;
}
//calculate the sum according to Luhn's algorithm
int calculate_credit_card_luhn_sum(long credit_card)
{
    int sum = 0;
    int multiply;
    int credit_two;
    long card = credit_card / 10;
    // The sum of the last number downwards
    while (credit_card > 0)
    {
        int credit = credit_card % 10;
        sum += credit;
        credit_card = credit_card / 100;

    }
    // the sum of the second to the last number downwards
    while (card > 0)
    {
        credit_two = card % 10;
        multiply = credit_two * 2;
        if (multiply > 9)
        {
            sum += multiply % 10 + multiply / 10;
        }
        else
        {
            sum += multiply;
        }

        card = card / 100;
    }


    return sum;

}
//count the length
int check_length(long credit_card)
{
    int credit_card_length = 0;
    while (credit_card != 0)
    {
        credit_card = credit_card / 10;
        credit_card_length++;
    }
    return credit_card_length;
}
//get the divisor
long check_digit(int credit_card_length)
{
    long divisor = 10;

    for (int i = 0; i < credit_card_length - 2; i++)
    {
        divisor = divisor * 10;
    }

    return divisor;
}
