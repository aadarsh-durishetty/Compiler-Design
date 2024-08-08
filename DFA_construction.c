#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STATES 100
#define ALPHABET_SIZE 2
#define NUM_STATES 4
#define NUM_SYMBOLS 2

struct Transition_process
{
    int currentState;
    char symbol;
    int nextState;
};
// function to print the resultant transition table
void transitionTable(struct Transition_process table[], int numTransitions)
{
    printf(" \n Name: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
    printf(" \nTransition Table:\n");
    printf("--------------\n");
    printf("| Symbol | Present State | Next State |\n");
    printf("-----------------------------------\n");

    for (int i = 0; i < numTransitions; i++)
    {
        printf("|    %c     |    %d     |     %d       |\n", table[i].symbol, table[i].currentState, table[i].nextState);
        printf("-----------------------------------\n");
    }
}

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};
// function for construction of parse tree nodes
struct Node *createNode(char data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// function to print parse tree
void ParseTree(struct Node *node, int level)
{
    if (node == NULL)
        return;

    ParseTree(node->right, level + 1);

    for (int i = 0; i < level; i++)
        printf("    ");
    printf("%c\n", node->data);

    ParseTree(node->left, level + 1);
}
// function to print first(), follow() and last() positions
void FirstFollowLast(struct Node *node, int level)
{
    if (node == NULL)
        return;

    FirstFollowLast(node->right, level + 1);

    for (int i = 0; i < level; i++)
        printf("    ");
    printf("%c", node->data);

    // Print First() of every node
    printf("  First: { %c }", node->data);

    // Print Follow() of every node
    if (node->right != NULL && node->right->data != '$')
        printf("  Follow: { %c }", node->right->data);
    else if (node->left != NULL && node->left->data != '$')
        printf("  Follow: { %c }", node->left->data);

    // Print Last() of every node
    printf("  Last: { %c }\n", node->data);

    FirstFollowLast(node->left, level + 1);
}

int transition[MAX_STATES][ALPHABET_SIZE];
bool finalStates[MAX_STATES];
// function to initialize the DFA
void initializeDFA()
{
    memset(transition, -1, sizeof(transition));
    memset(finalStates, false, sizeof(finalStates));
}
// function to add transition states
void addTransition(int state, int input, int nextState)
{
    transition[state][input] = nextState;
}
// function to add to the final state
void addFinalState(int state)
{
    finalStates[state] = true;
}
// function to check if string can be parsed
bool checkAccepted(char *input)
{
    int currentState = 0;
    int length = strlen(input);

    for (int i = 0; i < length; i++)
    {
        int inputIndex = input[i] - 'a';
        currentState = transition[currentState][inputIndex];
        if (currentState == -1)
            return false;
    }

    return finalStates[currentState];
}

int main()
{
    // Construct the parse tree manually
    struct Node *root = createNode('*');
    root->left = createNode('+');
    root->right = createNode('$');

    root->left->left = createNode('a');
    root->left->right = createNode('*');

    root->left->right->left = createNode('.');
    root->left->right->right = createNode('b');

    root->left->right->left->left = createNode('a');
    root->left->right->left->right = createNode('a');

    // Print the parse tree
    printf("\nName: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
    printf("\nParse Tree for (a+aa*b)*:\n");
    ParseTree(root, 0);
    printf("\n-------------------------------------------------------\n");
    printf(" \nName: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
    printf("\n Finding First(), Follow() and Last() for (a+aa*b)*:\n");
    FirstFollowLast(root, 0);

    // Define the states
    enum State
    {
        Q0,
        Q1,
        Q2,
        Q3
    };

    // Define the alphabet symbols
    char alphabet[NUM_SYMBOLS] = {'a', 'b'};

    // Define the transition table
    struct Transition_process table[] = {
        {Q0, 'a', Q1},
        {Q0, 'b', Q3},
        {Q1, 'a', Q1},
        {Q1, 'b', Q2},
        {Q2, 'a', Q3},
        {Q2, 'b', Q3},
        {Q3, 'a', Q1},
        {Q3, 'b', Q3}};

    // Calculate the number of transitions
    int numTransitions = sizeof(table) / sizeof(table[0]);

    // Print the transition table
    transitionTable(table, numTransitions);
    initializeDFA();

    // Add transitions for the regular expression (a+aa*b)*
    addTransition(0, 0, 1);
    addTransition(0, 1, -1);
    addTransition(1, 0, -1);
    addTransition(1, 1, 2);
    addTransition(2, 0, 3);
    addTransition(2, 1, -1);
    addTransition(3, 0, -1);
    addTransition(3, 1, 2);
    addTransition(3, 0, 1);
    addFinalState(1);
    addFinalState(2);
    addFinalState(3);
    // input of expression from the user
    char input[100];
    printf("\nName: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
    printf("Enter the input string: ");
    scanf("%s", input);
    // checking the acceptance of string
    if (checkAccepted(input))
    {
        printf("\nName: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
        printf("Accepted\n");
    }
    else
    {
        printf("\nName: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
        printf("Not Accepted\n");
    }
    return 0;
}