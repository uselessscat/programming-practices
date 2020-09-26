// Implements a dictionary's functionality
#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "dictionary.h"

unsigned int hash_internal(const char* data, unsigned int length);

// Represents a node in a hash table
typedef struct node
{
    unsigned int length;
    unsigned int hash;
    char* word;

    struct node* next;
}
node;

// Number of buckets in hash table
const unsigned int N = 150000;

// Hash table
node* table[150000];

unsigned int elements = 0;
unsigned int seed = 0;

char* mdictionary = NULL;

unsigned int strtolow(const char* origin, char* destiny)
{
    int i = 0;
    for (i = 0; origin[i]; i++)
    {
        destiny[i] = tolower(origin[i]);
    }

    destiny[i] = 0;
    return i;
}

long filesize(FILE* file) {
    long oldpos = ftell(file);

    fseek(file, 0L, SEEK_END);
    long size = ftell(file);

    fseek(file, 0L, oldpos);

    return size;
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

node* createNode(char* word, unsigned int length, unsigned int hash, node* parent)
{
    node* newNode = (node*)malloc(sizeof(node));

    if (newNode != NULL) {
        newNode->next = NULL;

        newNode->length = length;
        newNode->word = word;
        newNode->hash = hash;
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
node* searchLinkedList(node* nod, unsigned int hashval, char* word, unsigned int len, bool create)
{
    node* actual = nod;

    while (actual != NULL)
    {
        if (actual->length == len && actual->hash == hashval && strcmp(actual->word, word) == 0)
        {
            return actual;
        }
        else if (actual->next == NULL)
        {
            if (create)
            {
                return createNode(word, len, hashval, actual);
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
        return createNode(word, len, hashval, NULL);
    }
    else
    {
        return NULL;
    }
}

long readfile(const char* filename, char** buffer) {
    // open file then copy to memory
    FILE* file = fopen(filename, "rb");

    if (file == NULL) return 0;

    unsigned long size = filesize(file);

    if (size < 1) return 0;

    *buffer = (char*)malloc(size);

    if (*buffer == NULL) {
        fclose(file);

        return 0;
    }
    else {
        fread(*buffer, sizeof(char), size, file);

        fclose(file);
        return size;
    }
}

// Returns true if word is in dictionary else false
bool check(const char* word)
{
    char lword[LENGTH + 1];
    unsigned int len = strtolow(word, lword);

    unsigned int hashval = hash_internal(lword, len);
    unsigned int chash = hashval % N;

    node* actual = table[chash];

    node* item = searchLinkedList(actual, hashval, lword, len, false);

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

unsigned int hash(const char* data) {
    return hash_internal(data, strlen(data));
}

unsigned int hash_internal(const char* data, unsigned int length)
{
    // https://softwareengineering.stackexchange.com/a/145633/258205
    // I'm using MurmurHash 3 from https://github.com/aappleby/smhasher/blob/master/src/MurmurHash3.cpp#L94

    int nblocks = length / 4;

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

    switch (length & 3)
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
    h1 ^= length;

    h1 ^= h1 >> 16;
    h1 *= 0x85ebca6b;
    h1 ^= h1 >> 13;
    h1 *= 0xc2b2ae35;
    h1 ^= h1 >> 16;

    return h1;
}

bool add(char* word, int length)
{
    // dictionary always are lower haha
    //const char* lword[LENGTH + 1];
    //strtolow(word, lword);

    unsigned int hashval = hash_internal(word, length);
    unsigned int chash = hashval % N;

    node* actual = table[chash];

    node* location = searchLinkedList(actual, hashval, word, length, true);

    if (actual == NULL)
    {
        table[chash] = location;
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
    int size = readfile(dictionary, &mdictionary);

    if (!initHashTable(N))
    {
        //unload();

        return false;
    }

    // read the dictionary line-by-line and adds words to hashmap
    int lastLetterIndex = 0;
    // conver to index
    int i = size - 1;

    while (i > 0) {
        lastLetterIndex = i;
        mdictionary[lastLetterIndex] = 0;

        // assume that every word in dictionary ends with \n
        i--;
        while (i-- && mdictionary[i] != '\n');

        register int ti = i + 1;
        register int len = lastLetterIndex - ti;
        if (!add(&mdictionary[ti], len))
        {
            // free resources
            unload();

            return false;
        }
    }

    return true;
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

    free(mdictionary);

    return true;
}