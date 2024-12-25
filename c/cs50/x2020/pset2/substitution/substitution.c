#include <stdio.h>
#include <string.h>
#include <cs50.h>

#define CHARC 26 // char count

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");

        return 1;
    }

    if (strlen(argv[1]) != CHARC)
    {
        printf("Key must contain 26 characters.\n");

        return 1;
    }

    string key = argv[1];
    int map[CHARC];

    // generate offset map, this allow to apply both upper and lower case offset
    for (int i = 0; i < CHARC; i++)
    {
        // find duplicates
        for (int e = i + 1; e < CHARC; e++)
        {
            if (key[i] == key[e])
            {
                printf("Duplicated character in key.\n");

                return 1;
            }
        }

        // check valid chars
        if ((key[i] >= 'A' && key[i] <= 'Z') || (key[i] >= 'a' && key[i] <= 'z'))
        {
            // calculate offsets to apply in cipher text
            if (key[i] <= 'Z')
            {
                map[i] = key[i] - (i + 'A');
            }
            else
            {
                map[i] = key[i] - (i + 'a');
            }
        }
        else
        {
            printf("Invalid character in key.\n");

            return 1;
        }
    }

    // ask for text
    string text = get_string("plaintext: ");
    int textlen = strlen(text);

    // cipher
    for (int i = 0; i < textlen; i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = text[i] + map[text[i] - 'A'];
        }

        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = text[i] + map[text[i] - 'a'];
        }
    }

    printf("ciphertext: %s\n", text);

    return 0;
}
