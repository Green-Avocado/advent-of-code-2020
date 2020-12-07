#include <stdio.h>
#include <string.h>

#define bagNameSize 64

struct BagRule
{
    char name[bagNameSize];
    char subs[32][bagNameSize];
    int subCount[32];
    int numOfSubs;
};

struct BagRule addContents(struct BagRule rule, char *contains)
{
    rule.numOfSubs = 0;

    char *token;
    char s[8] = ",.";
    char modifier[bagNameSize / 2];
    char color[bagNameSize / 2];
    int count;

    if(strncmp(contains, "no other bags.", 14) == 0)
    {
        return rule;
    }

    token = strtok(contains, s);

    while(token != NULL)
    {
        sscanf(token, "%d %s %s", &count, modifier, color);

        sprintf(rule.subs[rule.numOfSubs], "%s %s", modifier, color);
        rule.subCount[rule.numOfSubs] = count;

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

struct BagRule getRule(char *key, struct BagRule *rules, int numOfRules)
{
    struct BagRule rule;

    for(int i = 0; i < numOfRules; i++)
    {
        if(strcmp(rules[i].name, key) == 0)
        {
            rule = rules[i];
            break;
        }
    }

    return rule;
}

int getContents(char *key, struct BagRule *rules, int numOfRules)
{
    int numOfContents = 0;
    struct BagRule rule = getRule(key, rules, numOfRules);

    for(int i =0; i < rule.numOfSubs; i++)
    {
        numOfContents += rule.subCount[i] * (1 + getContents(rule.subs[i], rules, numOfRules));
    }

    return numOfContents;
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

    result = getContents(target, rules, numOfRules);

    printf("%d\n", result);

    return 0;
}

