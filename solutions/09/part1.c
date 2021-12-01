#include <stdio.h>

#define PREAMBLE 25

int main()
{
    FILE *input;
    input = fopen("./input", "r");

    if(input == NULL)
    {
        puts("Error: could not read input file");
        return 1;
    }

    unsigned int nums[PREAMBLE + 1] = {0};
    int preamble = PREAMBLE;

    while(fscanf(input, "%u\n", nums + PREAMBLE) != EOF)
    {
        int valid = 0;

        if(preamble == 0)
        {
            for(int i = 0; i < PREAMBLE - 1; i++)
            {
                for(int ii = i + 1; ii < PREAMBLE; ii++)
                {
                    if(nums[i] + nums[ii] == nums[PREAMBLE])
                    {
                        valid = 1;
                        break;
                    }
                }

                if(valid == 1)
                {
                    break;
                }
            }
        }

        if(valid == 1 || preamble > 0)
        {
            for(int i = 0; i < PREAMBLE; i++)
            {
                nums[i] = nums[i + 1];
            }
        }
        else
        {
            break;
        }

        if(preamble > 0)
        {
            preamble--;
        }
    }

    printf("%u\n", nums[PREAMBLE]);

    return 0;
}

