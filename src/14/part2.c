#include <stdio.h>
#include <string.h>

#define MEMSIZE 108676
#define MASKSIZE 36

struct WrittenMem
{
    unsigned long int address;
    unsigned long int value;
};

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

void apply_mask(char *mask, char *address)
{
    for(int i = 0; i < MASKSIZE; i++)
    {
        if(mask[i] != '0')
        {
            address[i] = mask[i];
        }
    }
}

void write_from_mask(struct WrittenMem mem[MEMSIZE], char *address, unsigned long int value, unsigned int *memLength)
{
    int i = 0;

    while(address[i] != '\0')
    {
        if(address[i] == 'X')
        {
            char address0[64];
            char address1[64];

            strncpy(address0, address, 64);
            strncpy(address1, address, 64);

            address0[i] = '0';
            address1[i] = '1';

            write_from_mask(mem, address0, value, memLength);
            write_from_mask(mem, address1, value, memLength);

            break;
        }
        else
        {
            i++;
        }
    }

    if(address[i] == '\0')
    {
        unsigned long int address_dec = atoul(address);

        unsigned int i = 0;
        int isNew = 1;

        while(i < *memLength)
        {
            if(mem[i].address == address_dec)
            {
                isNew = 0;
                break;
            }
            else
            {
                i++;
            }
        }

        mem[i].value = value;

        if(isNew == 1)
        {
            mem[i].address = address_dec;
            *memLength = *memLength + 1;
        }
    }
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
    unsigned int memLength = 0;
    struct WrittenMem mem[MEMSIZE];

    while(fgets(line, sizeof(line), input) != NULL)
    {
        if(line[1] == 'a')
        {
            sscanf(line, "mask = %s", mask);
        }
        else
        {
            unsigned long int index;
            unsigned long int value;
            sscanf(line, "mem[%lu] = %lu", &index, &value);

            char index_bin[64];

            ultoa(index, index_bin, MASKSIZE);

            apply_mask(mask, index_bin);

            write_from_mask(mem, index_bin, value, &memLength);
        }
    }

    unsigned long int sum = 0;

    for(unsigned int i = 0; i < memLength; i++)
    {
        sum += mem[i].value;
    }

    printf("%lu\n", sum);

    return 0;
}

