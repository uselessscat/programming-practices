// Implements a dictionary's functionality
#pragma warning(disable : 4996)
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include <string.h>
#include <stdbool.h>

#include "dictionary.h"

#define INITIAL_ELEMENTS 8

// Represents a node in a hash table
typedef struct node
{
	unsigned int len;
	unsigned int hash;
	char word[LENGTH + 1];
}
node;

typedef struct HashTable
{
	unsigned int seed;
	unsigned int count;
	// Number of buckets in hash table
	unsigned int capacity;

	// pointer to array of node structs
	node(*elements)[];
}
hashtable;

hashtable* table;

unsigned int generateSeed()
{
	srand((unsigned int)time(NULL));

	return rand();
}

bool initHashTable(unsigned int initialCapacity)
{
	table = (hashtable*)malloc(sizeof(hashtable));

	if (table)
	{
		table->seed = generateSeed();
		table->count = 0;
		table->capacity = initialCapacity;

		// casting to a pointer -> nodes[]
		table->elements = (node(*)[]) calloc(initialCapacity, sizeof(node));

		if (table->elements == NULL)
		{
			return false;
		}

		return true;
	}
	else
	{
		return false;
	}
}

// Returns true if word is in dictionary else false
bool check(const char* word)
{
	// in order to check i have to convert to lower case
	char word_l[LENGTH + 1];

	strcpy_s(word_l, sizeof(word_l), word);

	for (int i = 0; word_l[i]; i++)
	{
		word_l[i] = tolower(word_l[i]);
	}

	// then hash and check
	unsigned int hashed = hash(word_l) % (table->capacity);

	if (strcmp(word_l, (*table->elements + hashed)->word) == 0)
	{
		return true;
	}

	return false;
}

inline unsigned int rotl32(unsigned int x, unsigned char r)
{
	return (x << r) | (x >> (32 - r));
}

// Hashes word to a number
unsigned int hash(const char* data)
{
	// https://softwareengineering.stackexchange.com/a/145633/258205
	// I'm using MurmurHash 3 from https://github.com/aappleby/smhasher/blob/master/src/MurmurHash3.cpp#L94

	unsigned int len = strlen(data);
	int nblocks = len / 4;

	unsigned int h1 = table->seed;

	unsigned int c1 = 0xcc9e2d51;
	unsigned int c2 = 0x1b873593;

	// body
	// point to the end 4 bytes block
	unsigned int* blocks = (unsigned int*)(data + nblocks * 4);

	// iterate from first block using negative indexes
	for (int i = -nblocks; i; i++)
	{
		unsigned int k1 = blocks[i];

		k1 *= c1;
		k1 = rotl32(k1, 15);
		k1 *= c2;

		h1 ^= k1;
		h1 = rotl32(h1, 13);
		h1 = h1 * 5 + 0xe6546b64;
	}

	// tail
	unsigned char* tail = (unsigned char*)(data + nblocks * 4);

	unsigned int k1 = 0;

	switch (len & 3)
	{
	case 3:
		k1 ^= tail[2] << 16;
	case 2:
		k1 ^= tail[1] << 8;
	case 1:
		k1 ^= tail[0];
		k1 *= c1;
		k1 = rotl32(k1, 15);
		k1 *= c2;
		h1 ^= k1;
	};

	// finalization
	h1 ^= len;

	h1 ^= h1 >> 16;
	h1 *= 0x85ebca6b;
	h1 ^= h1 >> 13;
	h1 *= 0xc2b2ae35;
	h1 ^= h1 >> 16;

	return h1;
}

bool add(const char* value, int lenght)
{
	unsigned int hashval = hash(value) % (table->capacity);

	strcpy((*table->elements + hashval)->word, value);
	(*table->elements + hashval)->len = lenght;
	table->count += 1;

	return true;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char* dictionary)
{
	FILE* file = fopen(dictionary, "r");

	if (file != NULL)
	{
		if (!initHashTable(INITIAL_ELEMENTS))
		{
			fclose(file);
			unload();

			return false;
		}

		char line[LENGTH + 1];

		// read the dictionary line-by-line and adds words to hashmap
		while (fgets(line, sizeof(line), file))
		{
			// fgets adds line ends, so we set lenght - 1 to 0x00
			int lenght = strlen(line) - 1;
			line[lenght] = 0;

			// if cant add a line to the dictionary then free resources and return false
			if (!add(line, lenght))
			{
				// free resources
				fclose(file);
				unload();

				return false;
			}
		}

		fclose(file);

		return true;
	}
	else
	{
		// can't open file
		return false;
	}
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
	return table->count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
	free(table->elements);
	free(table);

	return true;
}
