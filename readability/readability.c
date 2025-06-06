#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// prototype
int count_words(string text, int len);
int count_letters(string text, int len);
int count_sentences(string text, int len);

int main(void)
{
    // get text from user
    string text;
    int text_length = 0;

    do
    {
        text = get_string("Text: ");
        text_length = strlen(text);
    }
    while (text_length < 1);

    // get number of words, letters and sentences in text
    int no_of_words = count_words(text, text_length);
    int no_of_letters = count_letters(text, text_length);
    int no_of_sentences = count_sentences(text, text_length);

    // calculate the averages
    float average_letters = (float) no_of_letters / no_of_words * 100.0;
    float average_sentences = (float) no_of_sentences / no_of_words * 100.0;

    // use formula to calculate grade level (index = 0.0588 * L - 0.296 * S - 15.8)
    int index_level = round(0.0588 * average_letters - 0.296 * average_sentences - 15.8);

    // print relevant grade level
    if (index_level < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index_level > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index_level);
    }
}

// function to count the number of words in text
int count_words(string t, int len)
{
    int word_count = 0;   // initiates variable
    bool in_word = false; // flag that tracks whether we are inside a word

    // loop through the text
    for (int i = 0; i < len; i++)
    {
        // counts the first character of a word after a blank character as a word
        if (isgraph(t[i])) // check if it is a printable character (non-blank)
        {
            if (!in_word)
            {
                word_count++;
                in_word = true; // inside a word now
            }
        }
        else
        {
            in_word = false; // flag change to outside a word
        }
    }

    return word_count;
}

// function to count the number of letters in text
int count_letters(string t, int len)
{
    int letter_count = 0;
    for (int i = 0; i < len; i++)
    {
        if (isalpha(t[i]))
        {
            letter_count++;
        }
    }

    return letter_count;
}

// function to count the number of sentences in text
int count_sentences(string text, int len)
{
    int sentence_count = 0;
    for (int i = 0; i < len; i++)
    {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sentence_count++;
        }
    }

    return sentence_count;
}
