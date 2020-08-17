#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    string s = get_string("Text: ");

    // fix this
    int letters = 0, words = 1, sentences = 0;

    // iterate over the string to count letters, words ands sentences
    for (int i = 0; s[i] != 0; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            letters++;
        }

        if (s[i] == ' ')
        {
            words++;
        }

        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentences++;
        }
    }

    // calculate parameters S and L for the index
    float L = (float) letters / (float) words * 100.0;
    float S = (float) sentences / (float) words * 100.0;

    // Coleman-Liau index
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }

}