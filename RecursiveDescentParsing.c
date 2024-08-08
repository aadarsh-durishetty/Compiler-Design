#include <stdio.h>
#include <stdlib.h>

// production
// S -> A
// A -> X
// A -> abX
// X -> ab|bX|AX|E

bool S()
{
    A(n, string);
}

int A(int n, char string)
{
    X();
    for (int i = 0, i < n, i++)
    {
        if (string[i] == 'a' && string[i + 1] == 'b')
        {
        }

        X(n, string);
    }
}

int X(int n, char string)
{
    for (int i = 0, i < n; i++)
    {
        if (string[i] == 'a' && string[i + 1] == 'b')
        {
        }
        if (string[i] == 'b')
        {
        }
    }
    A(n, string);
    X(n, string);
}

int main()
{
    char string[100];
    int n;
    printf("Enter the string length: ");
    scanf("%d", &n);
    printf("Enter the string: ");
    scanf("%s", string);
}
