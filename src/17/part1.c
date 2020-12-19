#include <stdio.h>
#include <stdlib.h>

int getPos(int max_size, int x, int y, int z)
{
    return (x) + (y * max_size) + (z * max_size * max_size);
}

int getNewState(int max_size, int size, int *grid, int x, int y, int z)
{
    int activeNear = 0;

    for(int xx = x-1; xx <= x+1; xx++)
    {
        for(int yy = y-1; yy <= x+1; yy++)
        {
            for(int zz = z-1; zz <= z+1; zz++)
            {
                if(
                        (xx > 0 && xx < size) &&
                        (yy > 0 && yy < size) &&
                        (zz > 0 && zz < size)
                  )
                {
                    activeNear += grid[getPos(max_size, xx, yy, zz)];
                }
            }
        }
    }

    int currentState = grid[getPos(max_size, x, y, z)];

    if(
            (currentState == 1 && activeNear == 2) ||
            (activeNear == 3)
      )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int countActive(int max_size, int *grid)
{
    int active = 0;

    for(int i = 0; i < max_size * max_size * max_size; i++)
    {
        active += grid[i];
    }

    return active;
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

    char line[16];
    int max_size = 16;
    int size = 0;
    int *grid = (int*) calloc(16 * 16 * 16, sizeof(int));

    while(fgets(line, sizeof(line), input) != NULL)
    {
        int i = 0;
        while(line[i] == '.' || line[i] == '#')
        {
            if(line[i] == '#')
            {
                grid[getPos(max_size, i, size, 0)] = 1;
            }
            
            i++;
        }
        size++;
    }

    printf("%d\n", countActive(max_size, grid));

    return 0;
}

