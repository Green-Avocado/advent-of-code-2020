#include <stdio.h>

#define MEMSIZE 65536
#define MASKSIZE 36

void ultoa(unsigned long int ul, char *a, unsigned int length)
{
    for(int i = 0; i < length; i++)
    {
        unsigned long int bitvalue = 1UL << (length - 1 - i);

        if(ul >= bitvalue)
        {
            ul -= bitvalue;
            a[i] = '1';
        }
        else
        {
            a[i] = '0';
        }
    }

    a[length] = '\0';
}

unsigned long int atoul(char *a)
{
    unsigned long int ul = 0;
    unsigned int index = 0;

    while(a[index] != '\0')
    {
        ul *= 2;
        
        if(a[index] == '1')
        {
            ul += 1;
        }

        index++;
    }

    return ul;
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

    char line[64];
    char mask[64];
    unsigned long int mem[MEMSIZE] = {0};

    while(fgets(line, sizeof(line), input) != NULL)
    {
        if(line[1] == 'a')
        {
            sscanf(line, "mask = %s", mask);
        }
        else
        {
            unsigned int index;
            unsigned long int value;
            sscanf(line, "mem[%u] = %lu", &index, &value);

            char value_bin[64];

            ultoa(value, value_bin, MASKSIZE);

            for(int i = 0; i < MASKSIZE; i++)
            {
                if(mask[i] != 'X')
                {
                    value_bin[i] = mask[i];
                }
            }

            value = atoul(value_bin);

            mem[index] = value;
        }
    }

    unsigned long int sum = 0;

    for(unsigned int i = 0; i < MEMSIZE; i++)
    {
        sum += mem[i];
    }

    printf("%lu\n", sum);

    return 0;
}

