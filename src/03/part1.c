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
    int width = 0;
    int trees = 0;
    int pos = 0;

    while(fgets(line, sizeof(line), input) != NULL)
    {
        if(width == 0)
        {
            for(int i = 0; i < sizeof(line); i++)
            {
                char c = line[i];

                if(c != '.' && c!= '#')
                {
                    width = i;
                    break;
                }
            }

            if(width == 0)
            {
                //exceeds max width
                return 1;
            }
        }

        if(line[pos] == '#')
        {
            trees++;
        }

        pos = (pos + 3) % width;
    }

    printf("%d\n", trees);

    return 0;
}

