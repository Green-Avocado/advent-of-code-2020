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

    int num;

    int size = 64 * sizeof(int);
    int i = 0;
    int *operands = (int *) malloc(size);

    while (fscanf(input, "%d\n", &num))
    {
        if(i == size)
        {
            size += 64 * sizeof(int);
            operands = (int *) realloc(operands, size);
        }

        for(int ii = 0; ii < i; ii++)
        {
            if(*(operands + ii) + num == 2020)
            {
                printf("%d\n", *(operands + ii) * num);

                free(operands);

                return 0;
            }
        }

        *(operands + i) = num;
        i++;
    }

    puts("No suitable pairs found\n");
    fclose(input);
}

