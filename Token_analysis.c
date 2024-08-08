#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Returns true if the token is a delimiter
bool checkDelimiter(char ch)
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
        ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}')
    {
        return (true);
    }
    return (false);
}

// Returns true if the token is an operator
bool checkOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '>' || ch == '<' ||
        ch == '=')
        return (true);
    return (false);
}

// Returns true if the token is an identifier
bool checkIdentifier(char *str)
{
    if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
        str[0] == '3' || str[0] == '4' || str[0] == '5' ||
        str[0] == '6' || str[0] == '7' || str[0] == '8' ||
        str[0] == '9' || checkDelimiter(str[0]) == true)
        return (false);
    return (true);
}

// Returns true if the token is a keyword
bool checkKeyword(char *str)
{
    if (!strcmp(str, "if") || !strcmp(str, "else") || !strcmp(str, "while") || !strcmp(str, "do") || !strcmp(str, "break") || !strcmp(str, "continue") || !strcmp(str, "int") || !strcmp(str, "double") || !strcmp(str, "float") || !strcmp(str, "return") || !strcmp(str, "char"))
        return (true);
    return (false);
}

// Returns true if the token is an integer
bool checkInteger(char *str)
{
    int i, len = strlen(str);

    if (len == 0)
        return (false);
    for (i = 0; i < len; i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' || (str[i] == '-' && i > 0))
            return (false);
    }
    return (true);
}

// Returns true if the token is a valid real number
bool checkRealNumber(char *str)
{
    int i, len = strlen(str);
    bool hasDecimal = false;

    if (len == 0)
        return (false);
    for (i = 0; i < len; i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != '.' ||
            (str[i] == '-' && i > 0))
            return (false);
        if (str[i] == '.')
            hasDecimal = true;
    }
    return (hasDecimal);
}

// Extracts the substrings to check the validity of token
char *subString(char *str, int left, int right)
{
    int i;
    char *subStr = (char *)malloc(
        sizeof(char) * (right - left + 2));

    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left + 1] = '\0';
    return (subStr);
}

// Parsing the input expression to check the validity of tokens
void Parser(char *str)
{
    int left = 0, right = 0;
    int len = strlen(str);

    while (right <= len && left <= right)
    {
        if (checkDelimiter(str[right]) == false)
            right++;

        if (checkDelimiter(str[right]) == true && left == right)
        {
            if (checkOperator(str[right]) == true)
            {
                printf("Name: DURISHETTY AADARSH,  Reg no: 21BCE3815 \n");
                printf("'%c' : token is an operator \n", str[right]);
            }
            right++;
            left = right;
        }
        else if (checkDelimiter(str[right]) == true && left != right || (right == len && left != right))
        {
            char *subStr = subString(str, left, right - 1);

            if (checkKeyword(subStr) == true)
            {
                printf("Name: DURISHETTY AADARSH,  Reg no: 21BCE3815 \n");
                printf("'%s' : token is a valid keyword \n", subStr);
            }
            else if (checkInteger(subStr) == true)
            {
                printf("Name: DURISHETTY AADARSH,  Reg no: 21BCE3815 \n");
                printf("'%s' : token is an integer \n", subStr);
            }
            else if (checkRealNumber(subStr) == true)
            {
                printf("Name: DURISHETTY AADARSH,  Reg no: 21BCE3815 \n");
                printf("'%s' : token is a real number \n", subStr);
            }
            else if (checkIdentifier(subStr) == true && checkDelimiter(str[right - 1]) == false)
            {
                printf("Name: DURISHETTY AADARSH,  Reg no: 21BCE3815 \n");
                printf("'%s' : token is a valid identifier \n", subStr);
            }
            else if (checkIdentifier(subStr) == false && checkDelimiter(str[right - 1]) == false)
            {
                printf("Name: DURISHETTY AADARSH,  Reg no: 21BCE3815 \n");
                printf("'%s' : token is not a valid identifier \n", subStr);
            }
            left = right;
        }
    }
    return;
}
// function to remove all the spaces
void removeSpaces(const char *str, char *result)
{
    int length = strlen(str);
    int count = 0;

    for (int i = 0; i < length; i++)
    {
        if (str[i] != ' ')
        {
            result[count++] = str[i];
        }
    }
    result[count] = '\0';
}
// function to derive all the possible substrings from expression string input
void generateSubstrings(const char *expression, char **substrings)
{
    int length = strlen(expression);
    int count = 0;

    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j <= length; j++)
        {
            int substringLength = j - i;
            char *substring = (char *)malloc((substringLength + 1) * sizeof(char));
            strncpy(substring, expression + i, substringLength);
            substring[substringLength] = '\0';
            substrings[count++] = substring;
        }
    }
}

// User defined main function
int main()
{
    // input expression from the user
    char expression[100] = "int a = b*{c+(d-e)};";

    printf("Name: DURISHETTY AADARSH,  Reg no: 21BCE3815 \n");
    printf("Input Expression: %s \n", expression);

    // Removing all the spaces from expression
    char expressionNoSpaces[strlen(expression) + 1];
    removeSpaces(expression, expressionNoSpaces);

    // Generating all the possible substrings
    int maxSubstrings = (strlen(expressionNoSpaces) * (strlen(expressionNoSpaces) + 1)) / 2;
    char *substrings[maxSubstrings];
    generateSubstrings(expressionNoSpaces, substrings);

    // Printing the data type by scanning each token of the expression
    for (int i = 0; i < maxSubstrings; i++)
    {
        if ((strcmp(substrings[i], "int") == 0 || strcmp(substrings[i], "if") == 0 || strcmp(substrings[i], "else") == 0 || strcmp(substrings[i], "while") == 0 || strcmp(substrings[i], "do") == 0 || strcmp(substrings[i], "break") == 0 || strcmp(substrings[i], "continue") == 0 || strcmp(substrings[i], "int") == 0 || strcmp(substrings[i], "double") == 0 || strcmp(substrings[i], "float") == 0 || strcmp(substrings[i], "char") == 0))
        {
            printf("Name: DURISHETTY AADARSH,  Reg no: 21BCE3815 \n");
            printf("%s : the token is a keywoprd \n", substrings[i]);
        }
        else if ((strcmp(substrings[i], "0") == 0 || strcmp(substrings[i], "1") == 0 || strcmp(substrings[i], "2") == 0 || strcmp(substrings[i], "3") == 0 || strcmp(substrings[i], "4") == 0 || strcmp(substrings[i], "5") == 0 || strcmp(substrings[i], "6") == 0 || strcmp(substrings[i], "7") == 0 || strcmp(substrings[i], "8") == 0 || strcmp(substrings[i], "9") == 0))
        {
            printf("Name: DURISHETTY AADARSH,  Reg no: 21BCE3815 \n");
            printf("%s : the token is an integer \n", substrings[i]);
        }
        else if ((strcmp(substrings[i], "'") == 0 || strcmp(substrings[i], ":") == 0 || strcmp(substrings[i], ";") == 0 || strcmp(substrings[i], "/") == 0 || strcmp(substrings[i], "{") == 0 || strcmp(substrings[i], "}") == 0 || strcmp(substrings[i], "(") == 0 || strcmp(substrings[i], ")") == 0 || strcmp(substrings[i], "|") == 0))
        {
            printf("Name: DURISHETTY AADARSH,  Reg no: 21BCE3815 \n");
            printf("%s : the token is a delimter \n", substrings[i]);
        }
        else if ((strcmp(substrings[i], "+") == 0 || strcmp(substrings[i], "/") == 0 || strcmp(substrings[i], "*") == 0 || strcmp(substrings[i], "-") == 0 || strcmp(substrings[i], "^") == 0 || strcmp(substrings[i], ">") == 0 || strcmp(substrings[i], "<") == 0 || strcmp(substrings[i], ">>") == 0 || strcmp(substrings[i], "<<") == 0 || strcmp(substrings[i], "=") == 0))
        {
            printf("Name: DURISHETTY AADARSH,  Reg no: 21BCE3815 \n");
            printf("%s : the token is an operator \n", substrings[i]);
        }
        else if ((strcmp(substrings[i], "a") == 0 || strcmp(substrings[i], "b") == 0 || strcmp(substrings[i], "c") == 0 || strcmp(substrings[i], "d") == 0 || strcmp(substrings[i], "e") == 0 || strcmp(substrings[i], "f") == 0 || strcmp(substrings[i], "g") == 0))
        {
            printf("Name: DURISHETTY AADARSH,  Reg no: 21BCE3815 \n");
            printf("%s : the token is an identifier \n", substrings[i]);
        }
    }
    printf("---------------------------------------------------------");
    // Calling the parse functio to check the validity of the tokens
    printf("\n Checking the valid tokens by parsing the substrings: \n");
    // calling parsing function
    Parser(expression);

    return (0);
}