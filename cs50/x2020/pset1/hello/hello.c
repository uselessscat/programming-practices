#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // ask for the name and save to a variable called "name"
    string name = get_string("What is your name?\n");

    // print the value of "name"
    printf("hello, %s\n", name);
}