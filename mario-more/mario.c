#include <cs50.h>
#include <stdio.h>

int get_input(void);
void print_char(char c, int n);

int main(void)
{
    int height = get_input();
    for (int i = 0; i < height; i++)
    {
        print_char(' ', height - i - 1); // starting white spaces
        print_char('#', i + 1);          // left side of the pyramid
        print_char(' ', 2);              // gap in the centre
        print_char('#', i + 1);          // right side of the pyramid
        printf("\n");                    // start next line
    }
}

// Get input that is between 1 and 8 inclusive
int get_input(void)
{
    int n;
    do
    {
        n = get_int("Number: ");
    }
    while (n < 1 || n > 8);
    return n;
}

// Print character 'count' times
void print_char(char c, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", c);
    }
}
