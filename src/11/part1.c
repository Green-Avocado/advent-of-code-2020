#include <stdio.h>
#include <string.h>

#define MAXH 128
#define MAXW 128

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
            int filledNear = 0;

            if(h > 0 && old[h - 1][w] == '#')
            {
                filledNear++;
            }

            if(h < height - 1 && old[h + 1][w] == '#')
            {
                filledNear++;
            }

            if(w > 0 && old[h][w - 1] == '#')
            {
                filledNear++;
            }

            if(w < width - 1 && old[h][w + 1] == '#')
            {
                filledNear++;
            }



            if(h > 0 && w > 0 && old[h - 1][w - 1] == '#')
            {
                filledNear++;
            }

            if(h < height - 1 && w > 0 && old[h + 1][w - 1] == '#')
            {
                filledNear++;
            }

            if(h > 0 && w < width - 1 && old[h - 1][w + 1] == '#')
            {
                filledNear++;
            }

            if(h < height - 1 && w < width - 1 && old[h + 1][w + 1] == '#')
            {
                filledNear++;
            }



            if(old[h][w] == 'L' && filledNear == 0)
            {
                seats[h][w] = '#';
                diffs++;
            }
            else if(old[h][w] == '#' && filledNear >= 4)
            {
                seats[h][w] = 'L';
                diffs++;
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

