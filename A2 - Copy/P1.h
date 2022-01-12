#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void bruteInversionCount(int *arr, int len, int *inversions, int *operations);

void divideInversionCount(int *arr, int len, int *inversions, int *operations);
int *arraySlice(int *arr, int len, int start, int end);
void merge(int *A, int A_len, int *B, int B_len, int *C, int C_len, int *inversions, int *operations);
void printArray(int *arr, int len);
void appendSlice(int *arr, int arr_start, int *new, int new_len, int new_start);