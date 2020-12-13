#include <stdio.h>
#include <string.h>

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
    int arrival;

    fscanf(input, "%d\n", &arrival);

    fgets(line, sizeof(line), input);

    int busses[128];
    int numOfBusses = 0;
    char delim[] = ",x";
    char *token;

    token = strtok(line, delim);

    while(token != NULL)
    {
        sscanf(token, "%d", busses + numOfBusses);
        numOfBusses++;

        token = strtok(NULL, delim);
    }

    int shortest = busses[0] - (arrival % busses[0]);
    int shortBus = 0;

    for(int i = 1; i < numOfBusses; i++)
    {
        int time = busses[i] - (arrival % busses[i]);

        if(time < shortest)
        {
            shortest = time;
            shortBus = i;
        }
    }

    printf("%d\n", shortest * busses[shortBus]);

    return 0;
}

