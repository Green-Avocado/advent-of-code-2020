#include <stdio.h>

struct Group
{
    int answers[26];
    int count;
};

struct Group addanswer(struct Group group, char answer)
{
    int ansnum = (int)answer - (int)'a';
    
    if(group.answers[ansnum] == 0)
    {
        group.answers[ansnum] = 1;
        group.count++;
    }

    return group;
}

struct Group addanswerline(struct Group group, char *answerline)
{
    int i = 0;
    
    while(answerline[i] != '\n')
    {
        group = addanswer(group, answerline[i]);
        i++;
    }

    return group;
}

struct Group init_group(struct Group group)
{
    for(int i = 0; i < 26; i++)
    {
        group.answers[i] = 0;
    }
    group.count = 0;
    
    return group;
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

    char line[256];
    struct Group groups[2048];
    int groupno = 0;
    int total = 0;

    groups[groupno] = init_group(groups[groupno]);

    while(fgets(line, sizeof(line), input) != NULL)
    {
        if(line[0] == '\n')
        {
            groupno++;
            groups[groupno] = init_group(groups[groupno]);
        }
        else
        {
            groups[groupno] = addanswerline(groups[groupno], line);
        }
    }

    for(int i = 0; i <= groupno; i++)
    {
        total += groups[i].count;
    }

    printf("%d\n", total);

    return 0;
}

