#include <stdio.h>
#include <string.h>

void modifyGrammar()
{
    char input[100], left[50], right[50], store1[10], tempProd[20], productions[25][50];
    int i = 0, j = 0, flag = 0, consumed = 0;
    printf("\nName: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
    printf("\nEnter the productions: \n");
    scanf("%1s->%s", left, right);
    printf("%s", right);

    while (sscanf(right + consumed, "%[^|]s", store1) == 1 && consumed <= strlen(right))
    {
        if (store1[0] == left[0])
        {
            flag = 1;
            sprintf(productions[i++], "%s --> %s%s'\0", left, store1 + 1, left);
        }
        else
            sprintf(productions[i++], "%s' --> %s%s'\0", left, store1, left);
        consumed += strlen(store1) + 1;
    }

    if (flag == 1)
    {
        sprintf(productions[i++], "%s --> epsilon\0", left);
        printf("\nName: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
        printf("\nThe productions after eliminating the Left Recursion and Refactoring are:\n");
        for (j = 0; j < i; j++)
            printf("%s\n", productions[j]);
    }
    else
    {
        printf("\nName: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
        printf("\nThe Given Production Grammar has no Left Recursion");
    }
}

int main()
{
    modifyGrammar();
    return 0;
}
