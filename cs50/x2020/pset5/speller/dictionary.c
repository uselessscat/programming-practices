// Implements a dictionary's functionality

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

// Number of buckets in hash table
const unsigned int N = 150000;

// Hash table
node* table[150000];

unsigned int elements = 0;
unsigned int seed = 0;

void strtolow(const char* origin, char* destiny)
{
    int i = 0;
    for (i = 0; origin[i]; i++)
    {
        destiny[i] = tolower(origin[i]);
    }

    destiny[i] = 0;
}

unsigned int generateSeed()
{
    srand((unsigned int)time(NULL));

    return rand();
}

bool initHashTable(unsigned int initialCapacity)
{
    seed = generateSeed();

    return true;
}

node* createNode(const char* word, node* parent)
{
    node* newNode = (node*)malloc(sizeof(node));

    if (newNode != NULL) {
        newNode->next = NULL;

        strcpy(newNode->word, word);
    }
    else {
        return NULL;
    }

    if (parent != NULL)
    {
        parent->next = newNode;
    }

    return newNode;
}

// return the node that contains the word, or allocates one
node* searchLinkedList(node* nod, const char* word, bool create)
{
    node* actual = nod;

    while (actual != NULL)
    {
        if (strcmp(actual->word, word) == 0)
        {
            return actual;
        }
        else if (actual->next == NULL)
        {
            if (create)
            {
                return createNode(word, actual);
            }
            else
            {
                return NULL;
            }
        }
        else
        {
            actual = actual->next;
        }
    }

    if (create)
    {
        return createNode(word, NULL);
    }
    else
    {
        return NULL;
    }
}

// Returns true if word is in dictionary else false
bool check(const char* word)
{
    char lword[LENGTH + 1];
    strtolow(word, lword);

    unsigned int hashval = hash(lword) % N;

    node* actual = table[hashval];

    node* item = searchLinkedList(actual, lword, false);

    if (item == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

static inline unsigned int rotl32(unsigned int x, unsigned char r)
{
    return (x << r) | (x >> (32 - r));
}

unsigned int hash(const char* data)
{
    // https://softwareengineering.stackexchange.com/a/145633/258205
    // I'm using MurmurHash 3 from https://github.com/aappleby/smhasher/blob/master/src/MurmurHash3.cpp#L94

    unsigned int len = strlen(data);
    int nblocks = len / 4;

    unsigned int h1 = seed;

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

bool add(const char* word, int lenght)
{
    // dictionary always are lower haha
    //const char* lword[LENGTH + 1];
    //strtolow(word, lword);

    unsigned int hashval = hash(word) % N;

    node* actual = table[hashval];

    node* location = searchLinkedList(actual, word, true);

    if (actual == NULL)
    {
        table[hashval] = location;
    }

    if (location != NULL)
    {
        elements++;
        return true;
    }
    else
    {
        return false;
    }
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char* dictionary)
{
    FILE* file = fopen(dictionary, "r");

    if (file != NULL)
    {
        if (!initHashTable(N))
        {
            fclose(file);
            unload();

            return false;
        }

        char line[LENGTH + 2];

        // read the dictionary line-by-line and adds words to hashmap
        while (fgets(line, sizeof(line), file))
        {
            // fgets adds line ends, so we set lenght - 1 to 0x00
            int lenght = strlen(line) - 1;
            line[lenght] = 0;
            //  I don't use fgets at all. In one way I would use fread once and be done reading in the file. Or just mmap once and be done with that.
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
    return elements;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (unsigned int i = 0; i < N; i++)
    {
        node* actual = table[i];

        while (actual != NULL) {
            node* next = actual->next;

            free(actual);
            actual = next;
        }
    }

    return true;
}
