#include <stdio.h>
#include <string.h>

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

int validPass(int valid, struct Pass pass)
{
    if(
            strncmp(pass.byr, "\0", 1) != 0 &&
            strncmp(pass.iyr, "\0", 1) != 0 &&
            strncmp(pass.eyr, "\0", 1) != 0 &&
            strncmp(pass.hgt, "\0", 1) != 0 &&
            strncmp(pass.hcl, "\0", 1) != 0 &&
            strncmp(pass.ecl, "\0", 1) != 0 &&
            strncmp(pass.pid, "\0", 1) != 0
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

