#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    int sourceState;
    int numDestinationStatesZero;
    int numDestinationStatesOne;
    int destinationStates[2][100];
} NFA_initial;

typedef struct
{
    int sourceStates[100];
    int numSourceStates;
    int numDestinationStatesZero;
    int numDestinationStatesOne;
    int destinationStates[2][100];
} Transition_process;

// conversion from NFA_initial to DFA with static transition table as input
int main()
{
    NFA_initial inputNFA[3];
    for (int i = 0; i < 3; i++)
    {
        inputNFA[i].numDestinationStatesZero = 0;
        inputNFA[i].numDestinationStatesOne = 0;
    }

    inputNFA[0].sourceState = 0;
    inputNFA[0].destinationStates[0][0] = 0;
    inputNFA[0].numDestinationStatesZero++;
    inputNFA[0].destinationStates[1][0] = 0;
    inputNFA[0].destinationStates[1][1] = 1;
    inputNFA[0].numDestinationStatesOne += 2;

    inputNFA[1].sourceState = 1;
    inputNFA[1].destinationStates[0][0] = -1;
    inputNFA[1].numDestinationStatesZero++;
    inputNFA[1].destinationStates[1][0] = 2;
    inputNFA[1].numDestinationStatesOne++;

    inputNFA[2].sourceState = 2;
    inputNFA[2].destinationStates[0][0] = -1;
    inputNFA[2].numDestinationStatesZero++;
    inputNFA[2].destinationStates[1][0] = -1;
    inputNFA[2].numDestinationStatesOne++;
    printf(" \n Name: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
    printf("NFA_initial transition table as the input:\n");
    printf("State\t a      b\n");
    for (int i = 0; i < 3; i++)
    {
        printf(" q%d ", inputNFA[i].sourceState);
        printf("    ");
        for (int end_zero = 0; end_zero < inputNFA[i].numDestinationStatesZero; end_zero++)
        {
            if (inputNFA[i].destinationStates[0][end_zero] == -1)
            {
                printf(" N/A ");
            }
            else
            {
                printf(" q%d ", inputNFA[i].destinationStates[0][end_zero]);
            }
        }
        printf("    ");
        for (int end_zero = 0; end_zero < inputNFA[i].numDestinationStatesOne; end_zero++)
        {
            if (inputNFA[i].destinationStates[1][end_zero] == -1)
            {
                printf(" N/A ");
            }
            else
            {
                printf("q%d ", inputNFA[i].destinationStates[1][end_zero]);
            }
        }
        printf("\n");
    }
    printf("\n");

    int index = 0;
    Transition_process dfa[3];
    dfa[index].numSourceStates = 0;
    dfa[index].numDestinationStatesZero = 0;
    dfa[index].numDestinationStatesOne = 0;
    dfa[index].sourceStates[0] = 0;
    dfa[index].numSourceStates++;
    dfa[index].destinationStates[0][0] = 0;
    dfa[index].numDestinationStatesZero++;
    dfa[index].destinationStates[1][0] = 0;
    dfa[index].destinationStates[1][1] = 1;
    dfa[index].numDestinationStatesOne += 2;

    index++;
    dfa[index].numSourceStates = 0;
    for (int i = 0; i < dfa[index - 1].numDestinationStatesOne; i++)
    {
        dfa[index].sourceStates[dfa[index].numSourceStates] = dfa[index - 1].destinationStates[1][i];
        dfa[index].numSourceStates++;
    }
    dfa[index].numDestinationStatesZero = 0;
    dfa[index].numDestinationStatesOne = 0;
    for (int i = 0; i < dfa[index].numSourceStates; i++)
    {
        for (int j = 0; j < inputNFA[dfa[index].sourceStates[i]].numDestinationStatesZero; j++)
        {
            if (inputNFA[dfa[index].sourceStates[i]].destinationStates[0][j] == -1)
            {
                break;
            }
            dfa[index].destinationStates[0][dfa[index].numDestinationStatesZero++] =
                inputNFA[dfa[index].sourceStates[i]].destinationStates[0][j];
        }
        for (int j = 0; j < inputNFA[dfa[index].sourceStates[i]].numDestinationStatesOne; j++)
        {
            if (inputNFA[dfa[index].sourceStates[i]].destinationStates[1][j] == -1)
            {
                break;
            }
            dfa[index].destinationStates[1][dfa[index].numDestinationStatesOne++] =
                inputNFA[dfa[index].sourceStates[i]].destinationStates[1][j];
        }
    }

    index++;
    dfa[index].numSourceStates = 0;
    for (int i = 0; i < dfa[index - 1].numDestinationStatesOne; i++)
    {
        dfa[index].sourceStates[dfa[index].numSourceStates] = dfa[index - 1].destinationStates[1][i];
        dfa[index].numSourceStates++;
    }
    dfa[index].numDestinationStatesZero = 0;
    dfa[index].numDestinationStatesOne = 0;
    for (int i = 0; i < dfa[index].numSourceStates; i++)
    {
        for (int j = 0; j < inputNFA[dfa[index].sourceStates[i]].numDestinationStatesZero; j++)
        {
            if (inputNFA[dfa[index].sourceStates[i]].destinationStates[0][j] == -1)
            {
                break;
            }
            dfa[index].destinationStates[0][dfa[index].numDestinationStatesZero++] =
                inputNFA[dfa[index].sourceStates[i]].destinationStates[0][j];
        }
        for (int j = 0; j < inputNFA[dfa[index].sourceStates[i]].numDestinationStatesOne; j++)
        {
            if (inputNFA[dfa[index].sourceStates[i]].destinationStates[1][j] == -1)
            {
                break;
            }
            dfa[index].destinationStates[1][dfa[index].numDestinationStatesOne++] =
                inputNFA[dfa[index].sourceStates[i]].destinationStates[1][j];
        }
    }

    index++;
    printf(" \n Name: DURISHETTY AADARSH, Reg no: 21BCE3815 \n");
    printf("DFA transition table after conversion: \n");
    printf("State\t a        b\n");
    for (int i = 0; i < index; i++)
    {
        printf(" q%d ", i);
        printf("    ");
        for (int end_zero = 0; end_zero < dfa[i].numDestinationStatesZero; end_zero++)
        {
            if (dfa[i].destinationStates[0][end_zero] == -1)
            {
                printf(" - ");
            }
            else
            {
                printf(" q%d ", dfa[i].destinationStates[0][end_zero]);
            }
        }
        printf("    ");
        for (int end_one = 0; end_one < dfa[i].numDestinationStatesOne; end_one++)
        {
            if (dfa[i].destinationStates[1][end_one] == -1)
            {
                printf(" - ");
            }
            else
            {
                printf(" q%d ", dfa[i].destinationStates[1][end_one]);
            }
        }
        printf("\n");
    }

    return 0;
}
