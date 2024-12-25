#pragma warning(disable : 4996)
// Implements a spell-checker
#include <ctype.h>
#include <stdio.h>

#include "dictionary.h"

// Undefine any definitions
#undef calculate
#undef getrusage

// Default dictionary
#define DICTIONARY "dictionaries/large"

int main(int argc, char* argv[])
{
	// Check for correct number of args
	if (argc != 2 && argc != 3)
	{
		printf("Usage: ./speller [DICTIONARY] text\n");
		return 1;
	}

	// Structures for timing data


	// Benchmarks
	double time_load = 0.0, time_check = 0.0, time_size = 0.0, time_unload = 0.0;

	// Determine dictionary to use
	char* dictionary = (argc == 3) ? argv[1] : DICTIONARY;

	// Load dictionary

	bool loaded = load(dictionary);


	// Exit if dictionary not loaded
	if (!loaded)
	{
		printf("Could not load %s.\n", dictionary);
		return 1;
	}

	// Calculate time to load dictionary


	// Try to open text
	char* text = (argc == 3) ? argv[2] : argv[1];
	FILE* file = fopen(text, "r");
	if (file == NULL)
	{
		printf("Could not open %s.\n", text);
		unload();
		return 1;
	}

	// Prepare to report misspellings
	printf("\nMISSPELLED WORDS\n\n");

	// Prepare to spell-check
	int index = 0, misspellings = 0, words = 0;
	char word[LENGTH + 1];

	// Spell-check each word in text
	for (int c = fgetc(file); c != EOF; c = fgetc(file))
	{
		// Allow only alphabetical characters and apostrophes
		if (isalpha(c) || (c == '\'' && index > 0))
		{
			// Append character to word
			word[index] = c;
			index++;

			// Ignore alphabetical strings too long to be words
			if (index > LENGTH)
			{
				// Consume remainder of alphabetical string
				while ((c = fgetc(file)) != EOF && isalpha(c));

				// Prepare for new word
				index = 0;
			}
		}

		// Ignore words with numbers (like MS Word can)
		else if (isdigit(c))
		{
			// Consume remainder of alphanumeric string
			while ((c = fgetc(file)) != EOF && isalnum(c));

			// Prepare for new word
			index = 0;
		}

		// We must have found a whole word
		else if (index > 0)
		{
			// Terminate current word
			word[index] = '\0';

			// Update counter
			words++;

			// Check word's spelling
			bool misspelled = !check(word);

			// Print word if misspelled
			if (misspelled)
			{
				printf("%s\n", word);
				misspellings++;
			}

			// Prepare for next word
			index = 0;
		}
	}

	// Check whether there was an error
	if (ferror(file))
	{
		fclose(file);
		printf("Error reading %s.\n", text);
		unload();
		return 1;
	}

	// Close text
	fclose(file);

	// Determine dictionary's size
	unsigned int n = size();

	bool unloaded = unload();

	// Abort if dictionary not unloaded
	if (!unloaded)
	{
		printf("Could not unload %s.\n", dictionary);
		return 1;
	}

	// Report benchmarks
	printf("\nWORDS MISSPELLED:     %d\n", misspellings);
	printf("WORDS IN DICTIONARY:  %d\n", n);
	printf("WORDS IN TEXT:        %d\n", words);
	printf("TIME IN load:         %.2f\n", time_load);
	printf("TIME IN check:        %.2f\n", time_check);
	printf("TIME IN size:         %.2f\n", time_size);
	printf("TIME IN unload:       %.2f\n", time_unload);
	printf("TIME IN TOTAL:        %.2f\n\n",
		time_load + time_check + time_size + time_unload);

	// Success
	return 0;
}