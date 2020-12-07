#include <stdio.h>

struct BagRule
{
    char name[64];
    char subs[16][64];
};

int main()
{
    FILE *input;
    input = fopen("./input", "r");

    if(input == NULL)
    {
        puts("Error: could not read input file");
        return 1;
    }

    int result = 0;

    while(fgets(line, sizeof(line), input) != NULL)
    {
    }

    printf("%d\n", result);

    return 0;
}

