#include <stdio.h>

void merge(int *dest, int *arr1, int *arr2, int length1, int length2)
{
    int ind1 = 0;
    int ind2 = 0;

    for(int i = 0; i < length1 + length2; i++)
    {
        if(ind2 == length2 || (ind1 < length1 && arr1[ind1] < arr2[ind2]))
        {
            dest[i] = arr1[ind1];
            ind1++;
        }
        else
        {
            dest[i] = arr2[ind2];
            ind2++;
        }
    }
}

void sort(int *nums, int length)
{
    if(length > 1)
    {
        int arr1[length / 2];
        int arr2[length - length / 2];

        for(int i = 0; i < length; i++)
        {
            if(i < length / 2)
            {
                arr1[i] = nums[i];
            }
            else
            {
                arr2[i - length / 2] = nums[i];
            }
        }

        sort(arr1, length / 2);
        sort(arr2, length - length / 2);

        merge(nums, arr1, arr2, length / 2, length - length / 2);
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

    int nums[128] = {0};
    int length = 0;

    while(fscanf(input, "%d\n", nums + length) != EOF)
    {
        length++;
    }

    sort(nums, length);

    for(int i = length; i > 0; i--)
    {
        nums[i] = nums[i - 1];
    }

    length++;
    nums[length] = nums[length - 1] + 3;
    nums[0] = 0;

    unsigned long int paths[128] = {0};
    paths[length] = 1;

    for(int i = length - 1; i >= 0; i--)
    {
        paths[i] = paths[i + 1];

        if(i + 2 <= length && nums[i + 2] - nums[i] <= 3)
        {
            paths[i] += paths[i + 2];

            if(i + 3 <= length && nums[i + 3] - nums[i] <= 3)
            {
                paths[i] += paths[i + 3];
            }
        }
    }

    printf("%lu\n", paths[0]);

    return 0;
}

