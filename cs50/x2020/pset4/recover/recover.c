#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BUFFER_SIZE 512

typedef uint8_t byte;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image");

        return 1;
    }

    FILE *raw_file = fopen(argv[1], "r");

    if (raw_file == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }

    // recovered count and actual file writting
    int recovered_count = 0;
    FILE *recovered_file = NULL;

    byte buffer[BUFFER_SIZE];

    // read until no bytes left
    while (fread(buffer, sizeof(byte), BUFFER_SIZE, raw_file) > 0)
    {
        // if jpg signature exist
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] ==  0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (recovered_file != NULL)
            {
                fclose(recovered_file);

                recovered_file = NULL;
            }

            // open next file to write the actual image found
            char filename[8];

            sprintf(filename, "%03i.jpg", recovered_count);

            recovered_count++;
            recovered_file = fopen(filename, "w");

            fwrite(buffer, sizeof(byte), BUFFER_SIZE, recovered_file);
        }
        else
        {
            // if no signature and a file is open, write contents
            if (recovered_file != NULL)
            {
                fwrite(buffer, sizeof(byte), BUFFER_SIZE, recovered_file);
            }
        }
    }

    // close file if is open
    if (recovered_file != NULL)
    {
        fclose(recovered_file);
    }

    return 0;
}
