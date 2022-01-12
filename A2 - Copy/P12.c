#include "P12.h"

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

    // This function call is equivalent to the mergeSort() call
    int B_len = half - 0;
    int *B = arraySlice(arr, len, 0, half);
    int C_len = len - half;
    int *C = arraySlice(arr, len, half, len);
    divideInversionCount(B, B_len, inversions, operations);
    divideInversionCount(C, C_len, inversions, operations);

    merge(arr, len, B, B_len, C, C_len, inversions, operations);

    if (B)
        free(B);
    if (C)
        free(C);
}

/**
 * @brief Merges B,C, into A
 * 
 * @param A Original array
 * @param A_len Length of original array
 * @param B Array representing the lower half 
 * @param B_len Length of lower half
 * @param C Array representing upper half
 * @param C_len Length of upper half
 * @param inversions Count of inversions
 * @param operations Count of operations
 */
void merge(int *A, int A_len, int *B, int B_len, int *C, int C_len, int *inversions, int *operations)
{
    int a = 0, b = 0, c = 0;

    while (b < B_len && c < C_len)
    {
        (*operations)++;
        if (B[b] <= C[c])
        {
            A[a] = B[b++];
        }
        else
        {
            A[a] = C[c++];
            (*inversions) += B_len - b;
        }
        a++;
    }

    if (b == B_len)
    {
        appendSlice(A, a, C, C_len, c);
    }
    else
    {
        appendSlice(A, a, B, B_len, b);
    }
}

/**
 * @brief Prints array of integers
 * 
 * @param arr Array of integers
 * @param len Length of array
 */
void printArray(int *arr, int len)
{
    if (!arr)
        return;

    for (int i = 0; i < len; i++)
        printf("[%d]: %d\n", i, arr[i]);
}

/**
 * @brief Returns a slice of arr from index start to end
 * 
 * @param arr Original array
 * @param len Length of original array
 * @param start Start index of slice
 * @param end End index of slice
 * @return int* Sliced array
 */
int *arraySlice(int *arr, int len, int start, int end)
{
    int slice_length = end - start;
    int *sliced = (int *)malloc(sizeof(int) * slice_length);

    int c = 0;

    for (int b = start; b < end; b++)
        sliced[c++] = arr[b];

    return sliced;
}

/**
 * @brief Appends a new array to the original starting at 'start'
 * 
 * @param arr Original array
 * @param arr_start Starting index within arr
 * @param new Array to be copied from
 * @param new_len Length of new array
 * @param new_start Starting index within new
 */
void appendSlice(int *arr, int arr_start, int *new, int new_len, int new_start)
{
    for (int i = new_start; i < new_len; i++)
        arr[arr_start++] = new[i];
}