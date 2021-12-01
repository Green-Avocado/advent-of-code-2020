#include <stdio.h>

struct Rule
{
    int low0;
    int high0;

    int low1;
    int high1;
};

int main()
{
    FILE *input;
    input = fopen("./input", "r");

    if(input == NULL)
    {
        puts("Error: could not read input file");
        return 1;
    }

    char line[1024];
    int stage = 0;
    int substage = 0;

    struct Rule rules[32];
    int rules_length = 0;

    while(fgets(line, sizeof(line), input) != NULL)
    {
        if(line[0] == '\n')
        {
            substage = 0;
            stage++;
        }
        else
        {
            switch(stage)
            {
                case 0:
                    sscanf
                    (
                        line,
                        "%*[^:] : %d-%d or %d-%d",
                        &rules[rules_length].low0,
                        &rules[rules_length].high0,
                        &rules[rules_length].low1,
                        &rules[rules_length].high1
                    );

                    rules_length++;

                    break;

                case 1:
                    break;

                case 2:
                    if(substage == 0)
                    {
                        substage++;
                    }

                    break;
            }
        }

        if(stage == 2 && substage == 1)
        {
            break;
        }
    }

    int testnum;
    int e_rate = 0;

    while(fscanf(input, "%d%*c", &testnum) != EOF)
    {
        int valid = 0;

        for(int i = 0; i < rules_length; i++)
        {
            if
            (
                (rules[i].low0 <= testnum && testnum <= rules[i].high0) ||
                (rules[i].low1 <= testnum && testnum <= rules[i].high1)
            )
            {
                valid = 1;
            }
        }

        if(valid == 0)
        {
            e_rate += testnum;
        }
    }

    printf("%d\n", e_rate);

    return 0;
}

