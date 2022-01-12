#include "Helpers.h"
#include "P1.h"

/**
 * @brief Assignment 2
 * @author Conor Roberts (#1056167)
 * @date February 22nd, 2021
 * 
 */


/**
 * @brief Counts inversions within an integer array using merge sort
 * 
 * @param arr Integer array
 * @param len Length of integer array
 * @param inversions Integer pointer to counter for inversions
 * @param operations Integer pointer to counter for operations
 */
void divideInversionCount(int *arr, int len, int *inversions, int *operations)
{
    if (len <= 1)
        return;

    // by default, C rounds down on non-whole division
    int half = len / 2;
    int c = 0;

    int B_len = half - 0;
    int *B = arraySlice(arr, len, 0, half);
    int C_len = len - half;
    int *C = arraySlice(arr, len, half, len);
    
    // This function call is equivalent to the mergeSort() call
    divideInversionCount(B, B_len, inversions, operations);
    divideInversionCount(C, C_len, inversions, operations);

    merge(arr, len, B, B_len, C, C_len, inversions, operations);

    if (B)
        free(B);
    if (C)
        free(C);
}