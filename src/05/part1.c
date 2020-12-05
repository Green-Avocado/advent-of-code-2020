#include <stdio.h>
#include <string.h>

struct Seat
{
    int row;
    int column;
    int id;
};

int get_row(char *ticket_row)
{
    int row = 0;
    int spaces = 128;

    for(int i = 0; i < 7; i++)
    {
        spaces /= 2;

        if(*(ticket_row + i) == 'B')
        {
            row += spaces;
        }
    }

    return row;
}

int get_col(char *ticket_col)
{
    int col = 0;
    int spaces = 8;

    for(int i = 0; i < 3; i++)
    {
        spaces /= 2;

        if(*(ticket_col + i) == 'R')
        {
            col += spaces;
        }
    }

    return col;
}

void make_seat(struct Seat *seat, char *ticket)
{
    char ticket_row[8] = {'\0'};
    char ticket_col[4] = {'\0'};

    strncpy(ticket_row, ticket, 7);
    strncpy(ticket_col, ticket+7, 3);

    seat->row = get_row(ticket_row);

    seat->column = get_col(ticket_col);

    seat->id = seat->row * 8 + seat->column;
}

int get_seats(struct Seat *seats, FILE *input)
{
    int seatno = 0;
    char line[16];

    while(fgets(line, sizeof(line), input) != NULL)
    {
        make_seat(seats + seatno, line);

        seatno++;
    }

    return seatno;
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

    int highID = 0;
    int numOfSeats = 0;
    struct Seat seats[1024];

    numOfSeats = get_seats(seats, input);

    for(int i = 0; i < numOfSeats; i++)
    {
        if((seats + i)->id > highID)
        {
            highID = (seats+i)->id;
        }
    }

    printf("%d\n", highID);

    return 0;
}

