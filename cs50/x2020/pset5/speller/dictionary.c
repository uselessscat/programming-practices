// Implements a dictionary's functionality
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

#include <string.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 214500;
unsigned int count = 0;
unsigned int collisions = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char word_l[LENGTH + 1];

    strcpy(word_l, word);

    for(int i = 0; word_l[i]; i++){
        word_l[i] = tolower(word_l[i]);
    }

    unsigned int hashed = hash(word_l);
    //printf("----%s %d\n", word, hashed);

    if (table[hashed] != NULL && strcmp(word_l, table[hashed]->word) == 0){
        //printf("CHECK TRUE");
        return true;
    }

    return false;
}

uint32_t rotl32( uint32_t x, int8_t r )
{
    return (x << r) | (x >> (32 - r));
}

uint32_t getblock32( const uint32_t * p, int i )
{
    return p[i];
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // https://softwareengineering.stackexchange.com/a/145633/258205
    // I'm porting MurmurHash 3 to C from https://github.com/aappleby/smhasher/blob/master/src/MurmurHash3.cpp#L94
    const uint32_t seed = 1;
    const uint32_t len = strlen(word);
    const uint8_t *data = (const uint8_t*) word;
    const int nblocks = len / 4;

    uint32_t h1 = seed;

    const uint32_t c1 = 0xcc9e2d51;
    const uint32_t c2 = 0x1b873593;

    // body

    const uint32_t * blocks = (const uint32_t *)(data + nblocks*4);

    for(int i = -nblocks; i; i++)
    {
        uint32_t k1 = getblock32(blocks, i);

        k1 *= c1;
        k1 = rotl32(k1,15);
        k1 *= c2;

        h1 ^= k1;
        h1 = rotl32(h1,13);
        h1 = h1*5+0xe6546b64;
    }

    // tail

    const unsigned char *tail = (const unsigned char*)(data + nblocks*4);

    uint32_t k1 = 0;

    switch(len & 3)
    {
    case 3: k1 ^= tail[2] << 16;
    case 2: k1 ^= tail[1] << 8;
    case 1: k1 ^= tail[0];
          k1 *= c1; k1 = rotl32(k1,15); k1 *= c2; h1 ^= k1;
    };

    //----------
    // finalization

    h1 ^= len;

    h1 ^= h1 >> 16;
    h1 *= 0x85ebca6b;
    h1 ^= h1 >> 13;
    h1 *= 0xc2b2ae35;
    h1 ^= h1 >> 16;

    // TODO:
    return h1 % (N - 1);
}

bool add(const char *value)
{
    char word[LENGTH + 1];
    strcpy(word, value);

    for(int i = 0; word[i]; i++){
        word[i] = tolower(word[i]);
    }

    unsigned int hashval = hash(word);

    if (table[hashval] != NULL)
    {
        collisions++;
        free(table[hashval]);
    }

    table[hashval] = (node*) malloc(sizeof(node));

    // dest, source wtf
    strcpy(table[hashval]->word, word);
    count += 1;
    // printf("---%s %d\n", value, hashval);
    return true;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");

    if (file != NULL)
    {
        char line[LENGTH + 1];
        unsigned int position = ftell(file); // starts at 0

        while (fgets(line, sizeof(line), file)) {
            // fgets adds \n to string ends :C
            int len = ftell(file) - position;
            line[len - 1] = 0x0;

            // if cant add a line to the dictionary then free resources and return false
            if(!add(line))
            {
                // free resources
                unload();
                fclose(file);

                return false;
            }

            position = ftell(file);
        }

        fclose(file);

        return true;
    } else {
        // can't open file
        return false;
    }
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for(int i = 0; i < N; i++)
    {
        if(table[i] != NULL)
        {
            free(table[i]);
        }
    }

    printf("COLLISIONS %d", collisions);

    return true;
}
