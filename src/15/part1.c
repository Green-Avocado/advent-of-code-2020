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

    int starters[8];
    int startersLen = 0;

    while(fscanf(input, "%d%*c", starters + startersLen) != EOF)
    {
        startersLen++;
    }

    int history[2020];

    for(int i = 0; i < 2020; i++)
    {
        if(i < startersLen)
        {
            history[i] = starters[i];
        }
        else
        {
            int age = 0;

            for(int j = 1; j < i; j++)
            {
                if(history[i - 1 - j] == history[i - 1])
                {
                    age = j;
                    break;
                }
            }

            history[i] = age;
        }
    }

    printf("%d\n", history[2019]);

    return 0;
}

