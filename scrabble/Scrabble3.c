#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// prototype
int get_number_of_player();
string get_word(int i);
int get_score(string s);
int get_winner(int score[], int NO_of_PLAYERS);

int main(void)
{
    // get number of players
    const int NO_OF_PLAYERS = get_number_of_player();

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
        printf("Player %i wins!\n", result);
    }
}

// function to get number of players
int get_number_of_player()
{
    int num = 0;
    do
    {
        num = get_int("Number of players: ");
    }
    while (num < 2);

    return num;
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
int get_winner(int score[], int NO_OF_PLAYERS)
{
    int winning_player = 1;
    int winning_score = score[0];
    bool is_tie = false;

    for (int i = 1; i < NO_OF_PLAYERS; i++)
    {
        if (score[i] > winning_score)
        {
            winning_score = score[i];
            winning_player = i + 1;
            is_tie = false;
        }
        else if (score[i] == winning_score)
        {
            is_tie = true;
        }
    }
    if (is_tie)
    {
        return -1;
    }
    return winning_player;
}
