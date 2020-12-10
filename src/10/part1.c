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

    int prev = 0;
    int skip1 = 0;
    int skip3 = 0;

    for(int i = 0; i < length; i++)
    {
        if(nums[i] - prev == 1)
        {
            skip1++;
        }
        else if(nums[i] - prev == 3)
        {
            skip3++;
        }

        prev = nums[i];
    }

    skip3++; //phone

    printf("%d\n", skip1 * skip3);

    return 0;
}

