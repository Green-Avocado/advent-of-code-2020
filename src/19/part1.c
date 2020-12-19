#include <stdio.h>

struct Rule
{
    int id;
    int type;
    char c;

    int subs[8][8];
    int subs_len;
    int subs_subs_len;
};

void merge(struct Rule *out, struct Rule *arr1, int len1, struct Rule *arr2, int len2)
{
    int ind1 = 0;
    int ind2 = 0;

    for(int i = 0; i < len1 + len2; i++)
    {
        if(ind2 >= len2 || (ind1 < len1 && arr1[ind1].id < arr2[ind2].id))
        {
            out[i] = arr1[ind1];
            ind1++;
        }
        else
        {
            out[i] = arr2[ind2];
            ind2++;
        }
    }
}

void sort(struct Rule *arr, int len)
{
    if(len > 1)
    {
        int len1 = len / 2;
        int len2 = len - len1;

        struct Rule arr1[len1];
        struct Rule arr2[len2];

        for(int i = 0; i < len; i++)
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

        merge(arr, arr1, len1, arr2, len2);
    }
}

int validate(char *message, struct Rule *rules, int rules_length)
{
    int valid = 1;

    return valid;
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
    int readingPhase = 0;

    struct Rule rules[256];
    int rules_length = 0;

    char messages[1024][128];
    int messages_length = 0;

    while(fgets(line, sizeof(line), input) != NULL)
    {
        if(line[0] == '\n')
        {
            readingPhase = 1;
        }
        else if(readingPhase == 0)
        {
            int index1;

            sscanf(line, "%d: %n", &(rules[rules_length].id), &index1);

            if(line[index1] == '"')
            {
                rules[rules_length].type = 0;
                rules[rules_length].c = line[index1 + 1];
            }
            else
            {
                //TODO
            }

            rules_length++;
        }
        else
        {
            sscanf(line, "%s", messages + messages_length);
            messages_length++;
        }
    }

    sort(rules, rules_length);

    int valid = 0;

    for(int i = 0; i < messages_length; i++)
    {
        valid += validate(messages[i], rules, rules_length);
    }

    printf("%d\n", valid);

    return 0;
}

