#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void print_grade(int readability);
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int calculate_readability(string text);

int main(void)
{
    string text = get_string("Text: ");

    int readability = calculate_readability(text);

    print_grade(readability);
}

void print_grade(int readability)
{
  if (readability < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (readability > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", readability);
    }
}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 32)
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
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentences++;
        }
    }
    return sentences;
}

int calculate_readability(string text)
{
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float average_letters = letters * 1.0 / words * 100;

    float average_sentences = sentences * 1.0 / words * 100;
    int readability = round(0.0588 * average_letters - 0.296 * average_sentences - 15.8);
    return readability;
}
