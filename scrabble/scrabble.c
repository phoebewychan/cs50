#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int NO_OF_PLAYERS = 2;

// prototype
string get_word(int i);
int get_score(string s);
int get_winner(int score[], int N);

int main(void)
{
    // define array for words and scores
    string words[NO_OF_PLAYERS];
    int scores[NO_OF_PLAYERS];

    for (int i = 0; i < NO_OF_PLAYERS; i++)
    {
        // get words from players
        words[i] = get_word(i);
        // get scores from word
        scores[i] = get_score(words[i]);
    }

    // determine which score is larger, or whether equals. print winner or tie.
    int result = get_winner(scores, NO_OF_PLAYERS);
    if (result == -1)
    {
        printf("Tie!\n");
    }
    else
    {
        printf("Player %i wins!\n", result + 1);
    }
}

// function to get input from players
string get_word(int i)
{
    string input = get_string("Player %i: ", i + 1);
    return input;
}

// function to return score
int get_score(string s)
{
    int score = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++)
    {
        // convert character to uppercase
        char current_char = toupper(s[i]);

        // check if current character is between A to Z inclusive
        if (current_char >= 'A' && current_char <= 'Z')
        {
            score += POINTS[current_char - 'A'];
        }
        // 0 points for other charcter
        else
        {
            score += 0;
        }
    }
    return score;
}

// check scores and determine winner or tie
int get_winner(int score[], int N)
{
    int max[2];
    max[0] = 0;
    max[1] = score[0];
    int i;
    for (i = 1; i < N; i++)
    {
        if (score[i] > max[1])
        {
            max[0] = i;
            max[1] = score[i];
        }
        else if (score[i] == max[1])
        {
            return -1;
        }
    }
    return max[0];
}
