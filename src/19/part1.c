#include <stdio.h>

struct Rule
{
    int id;
    int type;
    char c;

    int rule1A;
    int rule1B;
    int rule2A;
    int rule2B;
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

    char line[128];
    int readingPhase = 0;
    int length = 0;

    struct Rule rules[256];
    char messages[1024][128];

    while(fgets(line, sizeof(line), input) != NULL)
    {
        if(line[0] == '\n')
        {
            length = 0;
        }
        else
        {
            if(readingPhase = 0)
            {
                int index1;

                sscanf(line, "%d: %n", &(rules[length].id), &index1);

                if(line[index1] == '"')
                {
                    rules[length].type = 0;
                    rules[length].c = line[index1 + 1];
                }
                else
                {
                    int index2;

                    sscanf(line + index1, "%d %d%n", rules[length].rule1A, rules[length].rule1B);

                    index2 += index1;

                    if(line[index2] == '\0')
                    {
                        rules[length].type = 1;
                    }
                    else
                    {
                        rules[length].type = 2;
                        sscanf(line + index2, " | %d %d%n", rules[length].rule2A, rules[length].rule2B);
                    }
                }
            }
            else
            {
                sscanf(line, "%s", messages + length);
            }

            length++;
        }
    }

    printf("%d\n", length);

    return 0;
}

