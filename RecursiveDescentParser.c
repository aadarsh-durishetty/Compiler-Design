#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// for a fixed static production
int S();
int A();
int X();

char input[100];  // Global variable to store input string
int position = 0; // Global variable to point index of input string

int main()
{
    printf(" \n Name: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
    printf("Enter the input string: ");
    scanf("%s", input);

    if (S() && position == strlen(input))
    {
        printf(" \n Name: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
        printf("Input string is parsed successfully! \n");
    }
    else
    {
        printf(" \n Name: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
        printf("Input string cannot be parsed.\n");
    }
    return 0;
}

int S()
{
    return A();
}

int A()
{
    if (input[position] == 'X')
    {
        printf(" \n Name: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
        printf("production: A -> X is passed\n");
        return X();
    }

    else if (input[position] == 'a' && input[position + 1] == 'b')
    {
        position += 2;
        printf(" \n Name: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
        printf("production: X -> abX is passed\n");
        return X();
    }
    else
    {
        printf(" \n Name: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
        printf("production: X -> abX is failed\n");
    }
    return 0;
}

int X()
{
    if (input[position] == 'a' && input[position + 1] == 'b')
    {
        position += 2;
        printf(" \n Name: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
        printf("production X -> ab is passed\n");
        return 1;
    }
    else
    {
        printf(" \n Name: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
        printf("production X -> ab is failed\n");
    }
    if (input[position] == 'b')
    {
        position++;
        if (input[position] == 'X')
        {
            printf(" \n Name: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
            printf("production X -> bX is passed\n");
            return X();
        }
        else
        {
            printf(" \n Name: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
            printf("production X -> bX is failed\n");
        }
    }
    if (input[position] == 'A')
    {
        return A();
        if (input[position + 1] == 'a')
        {
            printf(" \n Name: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
            printf("production: X -> Aa is passed\n");
            position += 2;
            return 1;
        }
        else
        {
            printf(" \n Name: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
            printf("production: X -> Aa is failed\n");
        }
        return 1;
    }
}