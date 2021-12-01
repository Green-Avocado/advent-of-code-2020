#include <stdio.h>

unsigned long long int eval(char *eq, int *pickup)
{
    unsigned long long int result = 0;
    int i = 0;
    char op = '+';

    while(eq[i] != ')' && eq[i] != '\0' && eq[i] != '\n')
    {
        if(eq[i] == '(')
        {
            unsigned long long int arg;
            int shift;

            arg = eval(eq + i + 1, &shift);

            if(op == '+')
            {
                result += arg;
            }
            else
            {
                result *= arg;
            }

            i += shift + 1;
        }
        else if(eq[i] == '*' || eq[i] == '+')
        {
            op = eq[i];
        }
        else if(eq[i] != ' ')
        {
            unsigned int arg;
            int shift;

            sscanf(eq + i, "%u%n", &arg, &shift);

            if(op == '+')
            {
                result += arg;
            }
            else
            {
                result *= arg;
            }

            i += shift - 1;
        }

        i++;
    }

    if(pickup != NULL)
    {
        *pickup = i;
    }

    return result;
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

    char line[256];
    unsigned long long int sum = 0;

    while(fgets(line, sizeof(line), input) != NULL)
    {
        sum += eval(line, NULL);
    }

    printf("%llu\n", sum);

    return 0;
}

