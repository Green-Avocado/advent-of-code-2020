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

    char line[8];

    int x = 0;
    int y = 0;

    int wayx = 10;
    int wayy = 1;

    while(fgets(line, sizeof(line), input) != NULL)
    {
        char op;
        int arg;

        sscanf(line, "%c%d", &op, &arg);

        switch(op)
        {
            case 'N':
                wayy += arg;
                break;

            case 'S':
                wayy -= arg;
                break;

            case 'E':
                wayx += arg;
                break;

            case 'W':
                wayx -= arg;
                break;

            case 'L':
                for(int i = 0; i < arg; i += 90)
                {
                    int tmp = wayy;
                    wayy = wayx;
                    wayx = -tmp;
                }
                break;

            case 'R':
                for(int i = 0; i < arg; i += 90)
                {
                    int tmp = wayy;
                    wayy = -wayx;
                    wayx = tmp;
                }
                break;

            case 'F':
                x += wayx * arg;
                y += wayy * arg;
                break;
        }
    }

    if(x < 0)
    {
        x *= -1;
    }

    if(y < 0)
    {
        y *= -1;
    }

    printf("%d\n", x + y);

    return 0;
}

