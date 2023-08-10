#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int CheckGrade(string text);

int main(void)
{
    string text = get_string("Text: ");


    if (CheckGrade(text) < 1)
    {
        printf("Before Grade 1\n"); // if index is lower than 1
    }

    if (CheckGrade(text) > 15)
    {
        printf("Grade 16+\n"); // if index is 16 or higher
    }

    for (int i = 1; i < 16; i++)
    {
        if (CheckGrade(text) == i)
        {
            printf("Grade %i\n", i); // if index is == i
        }
    }
}

int CheckGrade(string text)
{
    int letters = 0, words = 0, sentences = 0;
    double S = 0, L = 0;

    for (int i = 0; i < strlen(text); i++) // counting letters
    {
        if (isalpha(text[i])) // counting letters
        {
            letters++; // if this char of var text is a letter, then increment var letters
        }

        if ((int)text[i] == 32) // counting words
        {
            words++; // if this char is a spacebar, then (assuming there was a word before it) increment var words
        }

        if ((int)text[i] == 33 || (int)text[i] == 63 || (int)text[i] == 46) // counting sentences
        {
            sentences++; // if this char is '!' or '?' or '.' respectively , then increment var sentences
        }
    }

    words++; // the above for loop misses the last word of the text, so this increment is for the Last word

    L = (double)letters / words * 100.0; //  L is the average number of letters per 100 words in the text
    S = (double)sentences / words * 100.0; //  S is the average number of sentences per 100 words in the text

    double index = 0.0588 * L - 0.296 * S - 15.8; //  Coleman-Liau's formula for grading text
    return round(index);
}

