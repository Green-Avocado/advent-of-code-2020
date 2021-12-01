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

    //     1
    //     ^
    //     |
    // 2 <-+-> 0
    //     |
    //     v
    //     3
    //
    int facing = 0;

    while(fgets(line, sizeof(line), input) != NULL)
    {
        char op;
        int arg;

        sscanf(line, "%c%d", &op, &arg);

        switch(op)
        {
            case 'N':
                y += arg;
                break;

            case 'S':
                y -= arg;
                break;

            case 'E':
                x += arg;
                break;

            case 'W':
                x -= arg;
                break;

            case 'L':
                facing = (facing + arg / 90) % 4;
                break;

            case 'R':
                facing = (facing + 4 - arg / 90) % 4;
                break;

            case 'F':
                switch(facing)
                {
                    case 0:
                        x += arg;
                        break;

                    case 1:
                        y += arg;
                        break;

                    case 2:
                        x -= arg;
                        break;

                    case 3:
                        y -= arg;
                        break;
                }
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

