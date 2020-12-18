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

    char line[256];
    int length = 0;

    while(fgets(line, sizeof(line), input) != NULL)
    {
        length++;
    }

    printf("%d\n", length);

    return 0;
}

