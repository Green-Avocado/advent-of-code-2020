#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Pass
{
    char byr[64];
    char iyr[64];
    char eyr[64];
    char hgt[64];
    char hcl[64];
    char ecl[64];
    char pid[64];
    char cid[64];
};

int validBYR(char* byr)
{
    int year;
    sscanf(byr, "%d", &year);

    if(1920 <= year && year <= 2002)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int validIYR(char* iyr)
{
    int year;
    sscanf(iyr, "%d", &year);

    if(2010 <= year && year <= 2020)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int validEYR(char* eyr)
{
    int year;
    sscanf(eyr, "%d", &year);

    if(2020 <= year && year <= 2030)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int validHGT(char* hgt)
{
    int num;
    char units[16];
    sscanf(hgt, "%d%s", &num, units);

    if(
            (strncmp(units, "cm", 3) == 0 && 150 <= num && num <= 193) ||
            (strncmp(units, "in", 3) == 0 && 59 <= num && num <= 76)
      )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int validHCL(char* hcl)
{
    int valid = 1;

    if(hcl[0] != '#')
    {
        valid = 0;
    }
    else if(strlen(hcl) != 7)
    {
        valid = 0;
    }
    else
    {
        for(int i = 1; i < 7; i++)
        {
            if(!isxdigit(hcl[i]))
            {
                valid = 0;
                break;
            }
        }
    }

    return valid;
}

int validECL(char* ecl)
{
    if(
            (strncmp(ecl, "amb", 4) == 0) ||
            (strncmp(ecl, "blu", 4) == 0) ||
            (strncmp(ecl, "brn", 4) == 0) ||
            (strncmp(ecl, "gry", 4) == 0) ||
            (strncmp(ecl, "grn", 4) == 0) ||
            (strncmp(ecl, "hzl", 4) == 0) ||
            (strncmp(ecl, "oth", 4) == 0)
      )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int validPID(char* pid)
{
    int valid = 1;

    if(strlen(pid) != 9)
    {
        valid = 0;
    }
    else
    {
        for(int i = 0; i < 9; i++)
        {
            if(!isdigit(pid[i]))
            {
                valid = 0;
                break;
            }
        }
    }

    return valid;

}

int validPass(int valid, struct Pass pass)
{
    if(
            validBYR(pass.byr) &&
            validIYR(pass.iyr) &&
            validEYR(pass.eyr) &&
            validHGT(pass.hgt) &&
            validHCL(pass.hcl) &&
            validECL(pass.ecl) &&
            validPID(pass.pid)
      )
    {
        valid++;
    }

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

    char line[256];
    struct Pass passports[1024];
    int passno = 0;
    int valid = 0;

    while(fgets(line, sizeof(line), input) != NULL)
    {
        if(strlen(line) == 1)
        {
            valid = validPass(valid, passports[passno]);
            passno++;
        }
        else
        {
            char *token;
            token = strtok(line, " \n");

            while(token != NULL) {
                if(strncmp(token, "byr", 3) == 0)
                {
                    strncpy(passports[passno].byr, token+4, 64);
                }
                else if(strncmp(token, "iyr", 3) == 0)
                {
                    strncpy(passports[passno].iyr, token+4, 64);
                }
                else if(strncmp(token, "eyr", 3) == 0)
                {
                    strncpy(passports[passno].eyr, token+4, 64);
                }
                else if(strncmp(token, "hgt", 3) == 0)
                {
                    strncpy(passports[passno].hgt, token+4, 64);
                }
                else if(strncmp(token, "hcl", 3) == 0)
                {
                    strncpy(passports[passno].hcl, token+4, 64);
                }
                else if(strncmp(token, "ecl", 3) == 0)
                {
                    strncpy(passports[passno].ecl, token+4, 64);
                }
                else if(strncmp(token, "pid", 3) == 0)
                {
                    strncpy(passports[passno].pid, token+4, 64);
                }
                else if(strncmp(token, "cid", 3) == 0)
                {
                    strncpy(passports[passno].cid, token+4, 64);
                }
                
                token = strtok(NULL, " \n");
            }
        }
    }

    valid = validPass(valid, passports[passno]);

    printf("%d\n", valid);

    return 0;
}

