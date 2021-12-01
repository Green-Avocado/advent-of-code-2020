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
    char delim[] = ",";
    char *token;

    token = strtok(line, delim);

    while(token != NULL)
    {
        if(*token == 'x')
        {
            busses[numOfBusses] = -1;
        }
        else
        {
            sscanf(token, "%d", busses + numOfBusses);
        }

        numOfBusses++;

        token = strtok(NULL, delim);
    }

    unsigned long long int increment = 1;
    unsigned long long int timestamp = 0;
    int valid = 0;

    while(valid < numOfBusses)
    {
        for(int i = valid; i < numOfBusses; i++)
        {
            if(busses[i] == -1)
            {
                valid++;
            }
            else if((timestamp + i) % busses[i] == 0)
            {
                valid++;
                increment *= busses[i];
            }
            else
            {
                break;
            }
        }
        
        if(valid < numOfBusses)
        {
            timestamp += increment;
        }
    }

    printf("%llu\n", timestamp);

    return 0;
}

