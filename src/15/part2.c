#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *input;
    input = fopen("./input", "r");

    if(input == NULL)
    {
        puts("Error: could not read input file");
        return 1;
    }

    int starters[8];
    int startersLen = 0;

    while(fscanf(input, "%d%*c", starters + startersLen) != EOF)
    {
        startersLen++;
    }

    unsigned int *history = calloc(30000000, sizeof(history[0]));
    unsigned int age_prev = 0;
    unsigned int age = 0;

    for(unsigned int i = 0; i + 1 < 30000000; i++)
    {
        if(i < startersLen)
        {
            history[starters[i]] = i + 1;
        }
        else
        {
            age_prev = age;

            if(history[age] == 0)
            {
                age = 0;
            }
            else
            {
                age = i + 1 - history[age];
            }

            history[age_prev] = i + 1;
        }
    }

    printf("%d\n", age);

    return 0;
}

