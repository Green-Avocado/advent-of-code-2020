#include <stdio.h>
#include <string.h>

#define bagNameSize 64

struct BagRule
{
    char name[bagNameSize];
    char subs[32][bagNameSize];
    int numOfSubs;
};

struct BagRule addContents(struct BagRule rule, char *contains)
{
    rule.numOfSubs = 0;

    char *token;
    char s[8] = ",.";
    char modifier[bagNameSize / 2];
    char color[bagNameSize / 2];

    if(strncmp(contains, "no other bags.", 14) == 0)
    {
        return rule;
    }

    token = strtok(contains, s);

    while(token != NULL)
    {
        sscanf(token, "%*d %s %s", modifier, color);
        sprintf(rule.subs[rule.numOfSubs], "%s %s", modifier, color);

        rule.numOfSubs++;

        token = strtok(NULL, s);
    }

    return rule;
}

struct BagRule makeRule(char *line)
{
    struct BagRule rule;

    char modifier[bagNameSize / 2];
    char color[bagNameSize / 2];
    char contains[1024];

    sscanf(line, "%s %s bags contain %[^\n]s", modifier, color, contains);

    sprintf(rule.name, "%s %s", modifier, color);

    rule = addContents(rule, contains);

    return rule;
}

int addTarget(char targets[][bagNameSize], int numOfTargets, char *newTarget)
{
    int isNew = 1;

    for(int i = 0; i < numOfTargets; i++)
    {
        if(strcmp(targets[i], newTarget) == 0)
        {
            isNew = 0;
            break;
        }
    }

    if(isNew == 1)
    {
        strncpy(targets[numOfTargets], newTarget, bagNameSize);
        numOfTargets++;
    }

    return numOfTargets;
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
    struct BagRule rules[1024];
    int numOfRules = 0;
    int result = 0;

    while(fgets(line, sizeof(line), input) != NULL)
    {
        rules[numOfRules] = makeRule(line);
        numOfRules++;
    }

    char *target = "shiny gold";
    char targets[1024][bagNameSize];
    int numOfTargets = 0;
    int oldNumOfTargets = numOfTargets;

    strncpy(targets[numOfTargets], target, bagNameSize);
    numOfTargets++;

    while(oldNumOfTargets != numOfTargets)
    {
        oldNumOfTargets = numOfTargets;

        for(int i = 0; i < numOfRules; i++)
        {
            struct BagRule testrule = rules[i];

            for(int ii = 0; ii < testrule.numOfSubs; ii++)
            {
                for(int iii = 0; iii < numOfTargets; iii++)
                {
                    if(strcmp(testrule.subs[ii], targets[iii]) == 0)
                    {
                        numOfTargets = addTarget(targets, numOfTargets, testrule.name);
                        break;
                    }
                }
            }
        }
    }

    result = numOfTargets - 1;

    printf("%d\n", result);

    return 0;
}

