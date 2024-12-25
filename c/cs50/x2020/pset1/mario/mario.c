#include <stdio.h>

#define BUFF_SIZE 8

int getnumber();
void fillwith(char *, char, int);

int main()
{
    // get a valid integer
    int height = getnumber();

    // i will use an array to create sequences of # and ' '
    char buff[BUFF_SIZE];

    // generate x lines, x == height
    for (int i = 1; i <= height; i++)
    {
        fillwith(buff, ' ', height - i);
        printf("%s", buff);

        fillwith(buff, '#', i);
        printf("%s  ", buff);

        fillwith(buff, '#', i);
        printf("%s\n", buff);
    }
}

int getnumber()
{
    int valid = 0, height = 0;

    do
    {
        // ask for a number
        printf("Height:");
        valid = scanf("%d", &height);

        // clear the buffer :C
        while (getchar() != '\n');
    }
    while (valid == 0 || height < 1 || height > 8);

    return height;
}

void fillwith(char *array, char ch, int count)
{
    for (int i = 0; i < count; i++)
    {
        array[i] = ch;
    }

    array[count] = 0;
}
