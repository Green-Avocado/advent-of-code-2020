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
    unsigned int allnums[1024] = {0};
    unsigned int target = -1;
    int length = 0;
    int preamble = PREAMBLE;

    while(fscanf(input, "%u\n", allnums + length) != EOF)
    {
        nums[PREAMBLE] = allnums[length];

        length++;

        if(target == -1)
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
                target = nums[PREAMBLE];
            }

            if(preamble > 0)
            {
                preamble--;
            }
        }
    }

    unsigned int sums[1024] = {0};
    int success = 0;

    for(int offset = 0; offset < length; offset++)
    {
        for(int i = 0; i + offset < length; i++)
        {
            sums[i] += allnums[i + offset];
            if(offset != 0 && sums[i] == target)
            {
                int lowest = allnums[i];
                int highest = allnums[i];

                for(int ii = i + 1; ii <= i + offset; ii++)
                {
                    if(allnums[ii] < lowest)
                    {
                        lowest = allnums[ii];
                    }

                    if(allnums[ii] > highest)
                    {
                        highest = allnums[ii];
                    }
                }

                printf("%u\n", highest + lowest);

                success = 1;
                break;
            }
        }

        if(success == 1)
        {
            break;
        }
    }
    
    if(success == 0)
    {
        puts("No solution");
        return 1;
    }

    return 0;
}

