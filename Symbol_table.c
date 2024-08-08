#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define max_length 100

typedef struct
{
    char token[50];
    char address[50];
    char type[50];
} SymbolTableEntry;

SymbolTableEntry symbolTable[max_length];
int tokenCount = 0;
// function to create symbol table
void createSymbolTable(const char *token, const char *address, const char *type)
{
    SymbolTableEntry entry;
    strcpy(entry.token, token);
    strcpy(entry.address, address);
    strcpy(entry.type, type);

    symbolTable[tokenCount++] = entry;
}
// function to print symbol table
void printSymbolTable()
{
    printf("  Token\t\t   Address\t\tType\n");
    printf("----------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < tokenCount; i++)
    {
        printf("Name: DURISHETTY AADARSH, Reg no: 21BCE3815  =>  ");
        printf("%s\t\t%s\t\t%s\n", symbolTable[i].token, symbolTable[i].address, symbolTable[i].type);
    }
}
// function to parse the each token of the expression
void parseExpression(const char *expression)
{
    char token[50];
    char address[50];
    char type[50];

    int i = 0;
    int j = 0;

    while (expression[i] != '\0')
    {
        if (isspace(expression[i]))
        {
            i++;
            continue;
        }
        if (isalpha(expression[i]))
        {
            while (isalnum(expression[i]))
            {
                token[j++] = expression[i++];
            }
            token[j] = '\0';
            if (strcmp(token, "int") == 0 || strcmp(token, "float") == 0 || strcmp(token, "double") == 0 || strcmp(token, "long") == 0 || strcmp(token, "char") == 0 || strcmp(token, "while") == 0 || strcmp(token, "do") == 0 || strcmp(token, "if") == 0 || strcmp(token, "else") == 0)
            {
                printf("            Student details:                  ");
                strcpy(address, "token address");
                strcpy(type, "keyword");
            }
            else
            {
                strcpy(address, "token address");
                strcpy(type, "identifier");
            }
            createSymbolTable(token, address, type);

            j = 0;
        }
        else if (ispunct(expression[i]))
        {
            token[j++] = expression[i++];
            token[j] = '\0';

            if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "/") == 0 || strcmp(token, "*") == 0 || strcmp(token, "^") == 0 || strcmp(token, "=") == 0)
            {
                strcpy(type, "operator");
            }
            else if (strcmp(token, ":") == 0 || strcmp(token, ";") == 0 || strcmp(token, "{") == 0 || strcmp(token, "}") == 0 || strcmp(token, "(") == 0 || strcmp(token, ")") == 0)
            {
                strcpy(type, "delimiter");
            }

            strcpy(address, "token address");
            createSymbolTable(token, address, type);

            j = 0;
        }
    }
    printSymbolTable();
}

int main()
{
    // input of expression from the user
    char expression[100];
    printf("\nName: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
    printf("Enter an expression: ");
    fgets(expression, sizeof(expression), stdin);
    // Remove newline character from the end of the expression
    expression[strcspn(expression, "\n")] = '\0';
    // function call of parsing function
    parseExpression(expression);
    return 0;
}