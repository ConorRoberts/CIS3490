#include "P1.h"
/**
 * @brief Assignment 2
 * @author Conor Roberts (#1056167)
 * @date February 22nd, 2021
 * 
 */

/**
 * @brief 
 * 
 * @param arr 
 * @param len 
 * @param inversions 
 * @param operations 
 */
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