#include <stdio.h>
#include <string.h>

struct OpCode
{
    char op[4];
    int arg;
    int called;
};

int runOp(struct OpCode *op, int *instruction, int *accumulator)
{
    if(op -> called != 0)
    {
        return 1;
    }

    op -> called += 1;

    if(strncmp(op -> op, "nop", 3) == 0)
    {
        (*instruction)++;
    }
    else if(strncmp(op -> op, "jmp", 3) == 0)
    {
        *instruction += op -> arg;
    }
    else if(strncmp(op -> op, "acc", 3) == 0)
    {
        *accumulator += op -> arg;
        (*instruction)++;
    }

    return 0;
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

    char line[1024];

    struct OpCode ops[1024];
    int numOfOps = 0;

    while(fgets(line, sizeof(line), input) != NULL)
    {
        sscanf(line, "%s %d", ops[numOfOps].op, &ops[numOfOps].arg);
        ops[numOfOps].called = 0;

        numOfOps++;
    }

    int instruction = 0;
    int accumulator = 0;

    for(int i = 0; i < numOfOps; i++)
    {
        for(int ii = 0; ii < numOfOps; ii++)
        {
            ops[ii].called = 0;
        }

        instruction = 0;
        accumulator = 0;

        if(i > 0)
        {
            if(strncmp(ops[i - 1].op, "nop", 3) == 0)
            {
                strncpy(ops[i - 1].op, "jmp", 4);
            }
            else if(strncmp(ops[i - 1].op, "jmp", 3) == 0)
            {
                strncpy(ops[i - 1].op, "nop", 4);
            }
        }

        if(strncmp(ops[i].op, "nop", 3) == 0)
        {
            strncpy(ops[i].op, "jmp", 4);
        }
        else if(strncmp(ops[i].op, "jmp", 3) == 0)
        {
            strncpy(ops[i].op, "nop", 4);
        }
        else
        {
            continue;
        }

        while(instruction < numOfOps)
        {
            if(runOp(ops + instruction, &instruction, &accumulator) != 0)
            {
                break;
            }
        }

        if(instruction >= numOfOps)
        {
            break;
        }
    }

    printf("%d\n", accumulator);

    return 0;
}

