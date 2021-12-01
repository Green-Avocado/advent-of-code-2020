#include <stdio.h>

unsigned long getTrees(char lines[][256], int width, int height, int dx, int dy)
{
    int x = 0;
    int trees = 0;

    for(int y = 0; y < height; y += dy)
    {
        if(lines[y][x] == '#')
        {
            trees++;
        }

        x = (x + dx) % width;
    }

    return trees;
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

    char lines[512][256];
    int width = 0;
    int height = 0;

    while(fgets(lines[height], sizeof(lines)[0], input) != NULL)
    {
        height++;

        if(width == 0)
        {
            for(int i = 0; i < sizeof(lines[0]); i++)
            {
                char c = lines[0][i];

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
    }

    unsigned long product = 
        getTrees(lines, width, height, 1, 1) *
        getTrees(lines, width, height, 3, 1) *
        getTrees(lines, width, height, 5, 1) *
        getTrees(lines, width, height, 7, 1) *
        getTrees(lines, width, height, 1, 2);

    printf("%lu\n", product);

    return 0;
}

