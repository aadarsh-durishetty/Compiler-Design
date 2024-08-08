#include <stdio.h>
#include <stdlib.h>

// Structure for syntax tree node
typedef struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node *createNode(char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to generate syntax tree
Node *generateSyntaxTree()
{
    Node *root = createNode('*');
    root->left = createNode('+');
    root->right = createNode('c');
    root->left->left = createNode('a');
    root->left->right = createNode('b');
    return root;
}

// Function to print the syntax tree in the desired format
void printSyntaxTree(Node *node, int depth)
{
    if (node != NULL)
    {
        for (int i = 0; i < depth; i++)
        {
            printf(" ");
        }
        if (node->left != NULL || node->right != NULL)
        {
            printf("%c\n", node->data);
            printSyntaxTree(node->left, depth + 2);
            printSyntaxTree(node->right, depth + 2);
        }
        else
        {
            printf("%c\n", node->data);
        }
    }
}
// Function to check if the input string is accepted
int isAccepted(Node *node, char *input)
{
    if (node == NULL)
        return 0;

    if (node->data == '*')
    {
        while (*input != '\0')
        {
            if (isAccepted(node->right, input))
                return 1;
            input++;
        }
        return isAccepted(node->right, input);
    }
    else if (node->data == '+')
    {
        if (isAccepted(node->left, input) || isAccepted(node->right, input))
            return 1;
    }
    else if (node->data == 'c')
    {
        if (*input == 'c' && *(input + 1) == '\0')
            return 1;
    }
    else
    {
        if (*input == node->data && *(input + 1) == '\0')
            return 1;
    }
    return 0;
}

int main()
{
    char input[100];

    // Generate syntax tree
    Node *root = generateSyntaxTree();

    // Print syntax tree
    printf("Syntax tree:\n");
    printSyntaxTree(root, 0);

    // Receive input string from the user
    printf("\nName: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
    printf("\nEnter the input string: ");
    scanf("%s", input);

    // Verify if the input string is accepted or not
    if (isAccepted(root, input))
        printf("Input string is accepted.\n");
    else
        printf("Input string is not accepted.\n");
    return 0;
}
