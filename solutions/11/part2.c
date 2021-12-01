#include <stdio.h>
#include <string.h>

#define MAXH 128
#define MAXW 128

int look_diagonal(char seats[MAXH][MAXW], int height, int width, int h, int w, int dy, int dx)
{
    int y = h + dy;
    int x = w + dx;

    while(0 <= x && x < width && 0 <= y && y < height)
    {
        if(seats[y][x] == 'L')
        {
            return 0;
        }
        else if(seats[y][x] == '#')
        {
            return 1;
        }

        y += dy;
        x += dx;
    }

    return 0;
}

int seats_round(char seats[MAXH][MAXW], int height, int width)
{
    char old[MAXH][MAXW];
    int diffs = 0;

    for(int h = 0; h < height; h++)
    {
        for(int w = 0; w < width; w++)
        {
            old[h][w] = seats[h][w];
        }
    }

    for(int h = 0; h < height; h++)
    {
        for(int w = 0; w < width; w++)
        {
            if(old[h][w] != '.')
            {
                int filledNear = 0;

                for(int dy = -1; dy <= 1; dy++)
                {
                    for(int dx = -1; dx <= 1; dx++)
                    {
                        if(dx != 0 || dy != 0)
                        {
                            filledNear += look_diagonal(old, height, width, h, w, dy, dx);
                        }
                    }
                }

                if(old[h][w] == 'L' && filledNear == 0)
                {
                    seats[h][w] = '#';
                    diffs++;
                }
                else if(old[h][w] == '#' && filledNear >= 5)
                {
                    seats[h][w] = 'L';
                    diffs++;
                }
            }
        }
    }

    return diffs;
}

int countFilled(char seats[128][128], int height, int width)
{
    int counter = 0;

    for(int h = 0; h < height; h++)
    {
        for(int w = 0; w < width; w++)
        {
            if(seats[h][w] == '#')
            {
                counter++;
            }
        }
    }

    return counter;
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

    char seats[MAXH][MAXW];
    int height = 0;
    int width = 0;

    while(fgets(seats[height], sizeof(seats[0]), input) != NULL)
    {
        height++;
    }

    width = strlen(seats[0]) - 1;

    while(seats_round(seats, height, width) != 0);

    printf("%d\n", countFilled(seats, height, width));

    return 0;
}

