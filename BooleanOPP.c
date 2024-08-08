#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// static production
// A --> !A
// A --> A&A
// A --> A|A
// A --> i

// A --> !A | A&A | A|A | i

char *stringInput;
int i = 0;
char lastEntry[6], stack[50], handles[][4] = {"!A", "A&A", "A|A", "i"};

int top = 0, l;
char prec[6][6] = {

    /*input*/

    /*stack    !   &   |   $   i */

    /*  ! */ '>',
    '>',
    '>',
    '>',
    '<',

    /*  & */ '<',
    '>',
    '>',
    '>',
    '<',

    /*  | */ '<',
    '<',
    '>',
    '>',
    '<',

    /*  $ */ '<',
    '<',
    '<',
    '<',
    '>',

    /* i */ '>',
    '>',
    '>',
    '>',
    'e',

};

int getindex(char c)
{
    switch (c)
    {
    case '!':
        return 0;
    case '&':
        return 1;
    case '|':
        return 2;
    case 'i':
        return 3;
    case '$':
        return 4;
    }
}

int shiftFunction()
{
    stack[++top] = *(stringInput + i++);
    stack[top + 1] = '\0';
}

int reduceFunction()
{
    int i, len, found, t;
    for (i = 0; i < 4; i++) // selecting handles
    {
        len = strlen(handles[i]);
        if (stack[top] == handles[i][0] && top + 1 >= len)
        {
            found = 1;
            for (t = 0; t < len; t++)
            {
                if (stack[top - t] != handles[i][t])
                {
                    found = 0;
                    break;
                }
            }
            if (found == 1)
            {
                stack[top - t + 1] = 'A';
                top = top - t + 1;
                strcpy(lastEntry, handles[i]);
                stack[top + 1] = '\0';
                return 1; // successful reduction
            }
        }
    }
    return 0;
}

void displayStack()
{
    int j;
    for (j = 0; j <= top; j++)
        printf("%c", stack[j]);
}

void displayInput()
{
    int j;
    for (j = i; j < l; j++)
        printf("%c", *(stringInput + j));
}

void main()
{
    int j;
    stringInput = (char *)malloc(50 * sizeof(char));
    printf("\nName: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
    printf("\nEnter the string\n");
    scanf("%s", stringInput);
    stringInput = strcat(stringInput, "$");
    l = strlen(stringInput);
    strcpy(stack, "$");
    printf("\nName: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
    printf("\nSTACK\tINPUT\tACTION");
    while (i <= l)
    {
        shiftFunction();
        printf("\n");
        displayStack();
        printf("\t");
        displayInput();
        printf("\tShift");
        if (prec[getindex(stack[top])][getindex(stringInput[i])] == '>')
        {
            while (reduceFunction())
            {
                printf("\n");
                displayStack();
                printf("\t");
                displayInput();
                printf("\tReduced: A->%s", lastEntry);
            }
        }
    }

    if (strcmp(stack, "$A$") == 0)
    {
        printf("\nName: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
        printf("\nInput string is accepted, successful!");
    }
    else
    {
        printf("\nName: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
        printf("\nInput string is not accepted, failed!");
    }
}
