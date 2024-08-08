#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"

// static production:
// A --> A+A
// A --> A-A
// A --> A*As
// A --> i|j

char ip_sym[15], stack[15];
int ip_ptr = 0, st_ptr = 0, len, i;
char store1[2], store2[2];
char operation[15];
void ShiftReduceParser();

void main()
{
    printf("\nName: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
    printf("\n\t\t transition table for shift reduce parser\n");
    printf("\n given production(static): \n");
    printf("\n A->A+A\n A->A-A");
    printf("\n A->A*A\n A->i|j \n");
    printf("\nName: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
    printf("\n enter the input string to be parsed: ");
    gets(ip_sym);
    printf("\n\t stack implementation for shift reduce parser: \n");
    printf("\n STACK\t\t INPUT \t\t OPERATION ");
    printf("\n");
    printf("\n $\t\t%s$\t\t\t START", ip_sym);
    strcpy(operation, "SHIFT ");
    store1[0] = ip_sym[ip_ptr];
    store1[1] = '\0';
    strcat(operation, store1);
    len = strlen(ip_sym);
    for (i = 0; i <= len - 1; i++)
    {
        stack[st_ptr] = ip_sym[ip_ptr];
        stack[st_ptr + 1] = '\0';
        ip_sym[ip_ptr] = ' ';
        ip_ptr++;
        printf("\n $%s\t\t%s$\t\t\t%s", stack, ip_sym, operation);
        strcpy(operation, "SHIFT ");
        store1[0] = ip_sym[ip_ptr];
        store1[1] = '\0';
        strcat(operation, store1);
        ShiftReduceParser();
        st_ptr++;
    }
    st_ptr++;
    ShiftReduceParser();
}
void ShiftReduceParser()
{
    int flag = 0;
    store2[0] = stack[st_ptr];
    store2[1] = '\0';
    if ((!strcmpi(store2, "i")) || (!strcmpi(store2, "j")))
    {
        stack[st_ptr] = 'A';
        if (!strcmpi(store2, "i"))
        {
            printf("\n $%s\t\t%s$\t\t\tA->i", stack, ip_sym);
        }
        else
        {
            printf("\n $%s\t\t%s$\t\t\tA->j", stack, ip_sym);
        }
        flag = 1;
    }
    if ((!strcmpi(store2, "+")) || (strcmpi(store2, "*")) || (!strcmpi(store2, "-")))
    {
        flag = 1;
    }
    if ((!strcmpi(stack, "A+A")) || (!strcmpi(stack, "A-A")) || (!strcmpi(stack, "A*A")))
    {
        strcpy(stack, "A");
        st_ptr = 0;
        if (!strcmpi(stack, "A+A"))
            printf("\n $%s\t\t%s$\t\t\tA->A+A", stack, ip_sym);
        else if (!strcmpi(stack, "E\E"))
            printf("\n $%s\t\t %s$\t\t\tA->A-A", stack, ip_sym);
        else
            printf("\n $%s\t\t%s$\t\t\tA->A*A", stack, ip_sym);
        flag = 1;
    }

    if (!strcmpi(stack, "A") && ip_ptr == len)
    {
        printf("\n $%s\t\t%s$\t\t\tACCEPT", stack, ip_sym);
        printf("\nName: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
        printf("\nThe input string is parsed SUCCESSFULLY!\n");
        getch();
        exit(0);
    }
    if (flag == 0)
    {
        printf("\n%s\t\t\t%s\t\t REJECT", stack, ip_sym);
        printf("\nName: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
        printf("\nThe input string parsing FAILED\n");
        exit(0);
    }
    return;
}
