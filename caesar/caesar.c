#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int ALPHABET_NO = 26;

int key_validation(string key_string);

int main(int argc, string argv[])
{
    // Checks if correct input is provided
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Gets key. Manipulates key to be an integer and within scope 0-26.
    int key = key_validation(argv[1]);

    // Gets user text input
    string text = get_string("plaintext:  ");
    int text_length = strlen(text);

    // Converts text to cipher
    char encrypted_message[text_length];
    for (int i = 0; i < text_length; i++)
    {
        char current_char = text[i];
        if (isupper(text[i]))
        {
            encrypted_message[i] = (((current_char - 'A') + key) % ALPHABET_NO) + 'A';
        }
        else if (islower(text[i]))
        {
            encrypted_message[i] = (((current_char - 'a') + key) % ALPHABET_NO) + 'a';
        }
        else
        {
            encrypted_message[i] = current_char;
        }
    }
    encrypted_message[text_length] = '\0';

    // Prints encrypted message
    printf("ciphertext: %s\n", encrypted_message);
    return 0;
}

// Function to validate and convert key string input
// Returns valid integer or exits if invalid input
int key_validation(string key_string)
{
    // Checks if char in input is digit number
    for (int i = 0, len = strlen(key_string); i < len; i++)
    {
        if (!isdigit(key_string[i]))
        {
            printf("Usage: ./caesar key\n");
            exit(1);
        }
    }

    // Convert key from string to int. Convert key to be less than 26.
    int key = atoi(key_string);
    if (key > ALPHABET_NO)
    {
        key = key % ALPHABET_NO;
    }

    return key;
}
