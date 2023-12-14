#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text); // getting number of letters
    int words = count_words(text);    // getting number of words
    float L = ((float)letters / words) * 100;

    int sentences = count_sentences(text);    // getting number of sentences
    float S = ((float)sentences / words) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8; // applying the formula
    int round_index = round(index);

    if (round_index < 1)
    {
        printf("Before Grade 1\n"); // printing the grades
    }
    else if (round_index <= 15 && round_index >= 1)
    {
        printf("Grade %i\n", round_index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isupper(text[i])) // everytime isupper encounters a aplabet it adds to letters
        {
            letters++;
        }
        if (islower(text[i])) // everytime islower encounters a aplabet it adds to letters
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
// after every word there is space except for last word os the text, so we add 1 word for each space and initialize it at 1 to compansate for last word.
    int words = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') // if text ends with `.` or `!` or `?` we add a sentence
        {
            sentences++;
        }
    }
    return sentences;
}

