#include <stdio.h>

int checkline(int a, int b, char c, char *pass, size_t passlen)
{
    if((*(pass + a - 1) == c) != (*(pass + b - 1) == c))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

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

    int valid = 0;

    while(fgets(line, sizeof(line), input) != NULL)
    {
        int a, b;
        char c;
        char pass[256];

        sscanf(line, "%d-%d %c: %s\n", &a, &b, &c, pass);

        valid += checkline(a, b, c, pass, sizeof(pass));
    }

    printf("%d\n", valid);

    return 0;
}

