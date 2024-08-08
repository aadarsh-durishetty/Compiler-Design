
#include <stdio.h>
#include <string.h>
char str[30];
int idx = 0;

int E()
{
    if (str[idx] == 'a')
    {
        idx++;
        if (E() == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (str[idx] == 'b')
    {
        return 1;
    }
    return 0;
}
int D()
{
    if (str[idx] == 'a')
    {
        idx++;
        if (E() == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (str[idx] == 'b')
    {
        idx++;
        return 1;
    }
    return 0;
}
int C()
{
    if (str[idx] == 'a')
    {
        idx++;
        if (D() == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (str[idx] == 'b')
    {
        idx++;
        if (C() == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

int B()
{
    if (str[idx] == 'a')
    {
        idx++;
        if (C() == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (str[idx] != 'a')
    {
        return 0;
    }
}
int A()
{
    if (str[idx] != 'b')
    {
        return 0;
    }
    if (str[idx] == 'b')
    {
        idx++;
        if (B() == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

int main()
{
    // ba(a+b)*ab
    //  transition table
    /*
    - a b
    A - B
    B C -
    C D C
    D E F
    E E F
    */
    printf("enter the string to be parsed\n");
    scanf("%s", str);
    if (A() == 1 && idx == strlen(str))
    {
        printf("string can be parsed");
    }
    else
    {
        printf("string cannot be parsed");
    }

    return 0;
}