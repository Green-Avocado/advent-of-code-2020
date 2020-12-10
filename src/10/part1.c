#include <stdio.h>

int main()
{
    FILE *input;
    input = fopen("./input", "r");

    if(input == NULL)
    {
        puts("Error: could not read input file");
        return 1;
    }

    int num;

    while(fscanf(input, "%u\n", &num) != EOF)
    {
    }

    printf("%u\n", num);

    return 0;
}

