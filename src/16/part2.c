#include <stdio.h>
#include <string.h>

struct Rule
{
    char name[32];

    int low0;
    int high0;

    int low1;
    int high1;
};

struct Field
{
    int index;
    int potential_rules[32];
    int prLength;
};

void parseNums(char line[128], int length, int *output)
{
    int str_index = 0;

    for(int i = 0; i < length; i++)
    {
        int read_len;

        sscanf(line + str_index, "%d%*c%n", output + i, &read_len);

        str_index += read_len;
    }
}

void merge(struct Field *arr, struct Field *arr1, struct Field *arr2, int len1, int len2)
{
    int ind1 = 0;
    int ind2 = 0;

    for(int i = 0; i < len1 + len2; i++)
    {
        if(ind2 == len2 || (ind1 < len1 && arr1[ind1].prLength < arr2[ind2].prLength))
        {
            arr[i] = arr1[ind1];
            ind1++;
        }
        else
        {
            arr[i] = arr2[ind2];
            ind2++;
        }
    }
}

void sort(struct Field *arr, int length)
{
    if(length > 1)
    {
        int len1 = length / 2;
        int len2 = length - length / 2;

        struct Field arr1[len1];
        struct Field arr2[len2];

        for(int i = 0; i < length; i++)
        {
            if(i < len1)
            {
                arr1[i] = arr[i];
            }
            else
            {
                arr2[i - len1] = arr[i];
            }
        }

        sort(arr1, len1);
        sort(arr2, len2);

        merge(arr, arr1, arr2, len1, len2);
    }
}

int solve(struct Field *fields, int *taken, int rules_length, int *rule_map, int index)
{
    if(index >= rules_length)
    {
        return 1;
    }

    int taken_copy[rules_length];

    for(int i = 0; i < rules_length; i++)
    {
        taken_copy[i] = taken[i];
    }

    for(int i = 0; i < rules_length; i++)
    {
        if(fields[index].potential_rules[i] == 1 && taken_copy[i] == 0)
        {
            taken_copy[i] = 1;

            if(solve(fields, taken_copy, rules_length, rule_map, index + 1) == 1)
            {
                rule_map[index] = i;
                return 1;
            }
            else
            {
                taken_copy[i] = 0;
            }
        }
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

    char line[128];
    int stage = 0;
    int substage = 0;

    struct Rule rules[32];
    int rules_length = 0;

    int myTicket[32];

    int nearby[256][32];
    int nearby_length = 0;

    unsigned long int result = 1;

    while(fgets(line, sizeof(line), input) != NULL)
    {
        if(line[0] == '\n')
        {
            substage = 0;
            stage++;
        }
        else
        {
            int valid_line;
            int valid_num;
            int testnum;

            switch(stage)
            {
                case 0:
                    sscanf
                    (
                        line,
                        "%[^:] : %d-%d or %d-%d",
                        rules[rules_length].name,
                        &rules[rules_length].low0,
                        &rules[rules_length].high0,
                        &rules[rules_length].low1,
                        &rules[rules_length].high1
                    );

                    rules_length++;

                    break;

                case 1:
                    if(substage == 0)
                    {
                        substage++;
                    }
                    else
                    {
                        parseNums(line, rules_length, myTicket);
                    }

                    break;

                case 2:
                    if(substage == 0)
                    {
                        substage++;
                    }
                    else
                    {
                        parseNums(line, rules_length, nearby[nearby_length]);

                        valid_line = 1;

                        for(int i = 0; i < rules_length; i++)
                        {
                            valid_num = 0;
                            testnum = nearby[nearby_length][i];

                            for(int j = 0; j < rules_length; j++)
                            {
                                if
                                (
                                    (rules[j].low0 <= testnum && testnum <= rules[j].high0) ||
                                    (rules[j].low1 <= testnum && testnum <= rules[j].high1)
                                )
                                {
                                    valid_num = 1;
                                    break;
                                }
                            }

                            if(valid_num == 0)
                            {
                                valid_line = 0;
                                break;
                            }
                        }

                        if(valid_line == 1)
                        {
                            nearby_length++;
                        }
                    }

                    break;
            }
        }
    }

    struct Field fields[rules_length];

    for(int i = 0; i < rules_length; i++)
    {
        fields[i].index = i;
        fields[i].prLength = rules_length;

        for(int j = 0; j < rules_length; j++)
        {
            fields[i].potential_rules[j] = 1;
        }

        for(int j = 0; j < nearby_length; j++)
        {
            for(int k = 0; k < rules_length; k++)
            {
                if(fields[i].potential_rules[k] == 1)
                {
                    struct Rule pRule = rules[k];

                    if
                    (
                        !(pRule.low0 <= nearby[j][i] && nearby[j][i] <= pRule.high0) &&
                        !(pRule.low1 <= nearby[j][i] && nearby[j][i] <= pRule.high1)
                    )
                    {
                        fields[i].potential_rules[k] = 0;
                        fields[i].prLength--;
                    }
                }
            }
        }
    }

    int rule_map[32];
    int taken[32] = {0};

    sort(fields, rules_length);
    solve(fields, taken, rules_length, rule_map, 0);

    for(int i = 0; i < rules_length; i++)
    {
        struct Field field = fields[i];
        struct Rule rule = rules[rule_map[i]];

        if(strncmp(rule.name, "departure", 9) == 0)
        {
            result *= myTicket[field.index];
        }
    }

    printf("%lu\n", result);

    return 0;
}

