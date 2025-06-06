#include <cs50.h>
#include <math.h>
#include <stdio.h>

long get_card_number(void);
string get_card_type(long card_number, int count);

int main(void)
{
    // Get input
    long card_number = get_card_number();
    long temp_card_number = card_number;
    int sum_multiplied_digits = 0;
    int sum_other_digits = 0;
    int count = 0;
    // Get digits from card number and add
    while (temp_card_number > 0)
    {
        int digit = temp_card_number % 10;

        if (count % 2 == 1)
        {
            int doubled_digit = digit * 2;
            if (doubled_digit > 9)
            {
                doubled_digit = doubled_digit / 10 + doubled_digit % 10;
            }
            sum_multiplied_digits += (doubled_digit);
        }
        else
        {
            sum_other_digits += digit;
        }
        temp_card_number /= 10;
        count++;
    }
    int total = sum_multiplied_digits + sum_other_digits;
    // printf("%i\n", total);
    // printf("%i\n", count);
    // If valid, check length and starting digits, print card type
    if (total % 10 == 0)
    {
        string card_type = get_card_type(card_number, count);
        printf("%s\n", card_type);
    }
    else
    {
        printf("INVALID\n");
    }
}

long get_card_number(void)
{
    long card_number;
    card_number = get_long("Number: ");
    return card_number;
}

// Function to determin the card type based on card number and digit count
string get_card_type(long card_number, int count)
{
    long first_two_digits = card_number / (long) pow(10, count - 2);
    long first_digit = card_number / (long) pow(10, count - 1);
    if ((count == 13 || count == 16) && first_digit == 4)
    {
        return ("VISA");
    }
    else if ((first_two_digits == 34 || first_two_digits == 37) && count == 15)
    {
        return ("AMEX");
    }
    else if ((first_two_digits >= 51 && first_two_digits <= 55) && count == 16)
    {
        return ("MASTERCARD");
    }
    return ("INVALID");
}
