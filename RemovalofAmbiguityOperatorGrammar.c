
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTIONS 100

// Structure to represent a production rule
typedef struct
{
    char left;
    char right[10];
} Production;

// Structure to represent a non-terminal symbol
typedef struct
{
    char symbol;
    Production productions[MAX_PRODUCTIONS];
    int count;
} NonTerminal;

NonTerminal nonTerminals[MAX_PRODUCTIONS];
int nonTerminalCount = 0;

// Function to check if a symbol is a non-terminal
bool isNonTerminal(char symbol)
{
    for (int i = 0; i < nonTerminalCount; i++)
    {
        if (nonTerminals[i].symbol == symbol)
        {
            return true;
        }
    }
    return false;
}

// Function to find the non-terminal index in the array
int findNonTerminalIndex(char symbol)
{
    for (int i = 0; i < nonTerminalCount; i++)
    {
        if (nonTerminals[i].symbol == symbol)
        {
            return i;
        }
    }
    return -1;
}

// Function to add a production rule to a non-terminal
void addProduction(char nonTerminal, char *right)
{
    int index = findNonTerminalIndex(nonTerminal);
    if (index != -1)
    {
        Production production;
        production.left = nonTerminal;
        strcpy(production.right, right);
        nonTerminals[index].productions[nonTerminals[index].count] = production;
        nonTerminals[index].count++;
    }
    else
    {
        NonTerminal newNonTerminal;
        newNonTerminal.symbol = nonTerminal;
        Production production;
        production.left = nonTerminal;
        strcpy(production.right, right);
        newNonTerminal.productions[0] = production;
        newNonTerminal.count = 1;
        nonTerminals[nonTerminalCount] = newNonTerminal;
        nonTerminalCount++;
    }
}

// Function to print the modified productions
void printProductions()
{
    for (int i = 0; i < nonTerminalCount; i++)
    {
        for (int j = 0; j < nonTerminals[i].count; j++)
        {
            printf(" \n Name: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
            printf("%c -> %s\n", nonTerminals[i].productions[j].left, nonTerminals[i].productions[j].right);
        }
    }
}

int main()
{
    // Adding the input productions
    addProduction('E', "E & E");
    addProduction('E', "E | E");
    addProduction('E', "id");

    // Removing the ambiguity
    addProduction('E', "E & A");
    addProduction('E', "A");
    addProduction('A', "A | B");
    addProduction('A', "B");
    addProduction('B', "id");

    // Printing the modified productions
    printf("Output productions before and after removing ambiguity:\n");
    printProductions();

    return 0;
}
