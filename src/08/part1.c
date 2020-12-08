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

    char line[1024];
    int result = 0;

    while(fgets(line, sizeof(line), input) != NULL)
    {
    }

    result = numOfTargets - 1;

    printf("%d\n", result);

    return 0;
}

