#include "P11.h"

void bruteInversionCount(int *arr, int len, int *inversions, int *operations)
{
    for (int i = len-1; i >=0; i--){
        for (int j = i+1; j < len; j++)
        {
            (*operations)++;
            if (arr[i] > arr[j])
                (*inversions)++;
        }
    }
}