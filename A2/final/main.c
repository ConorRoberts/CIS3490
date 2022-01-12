#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "P1.h"
#include "P2.h"
#include "Helpers.h"

/**
 * @brief Assignment 2
 * @author Conor Roberts (#1056167)
 * @date February 22nd, 2021
 * 
 */


#define LINE_LENGTH 256

int main(int argc, char *argv[])
{
    int int_len = 0, pt_len = 0, pt_len_2 = 0, inversions = 0, operations = 0;

    int *int_array = intArrayFromFile(argv[1], &int_len);
    Point *pt_array = pointArrayFromFile(argv[2], &pt_len);
    Point *pt_array_2 = pointArrayFromFile(argv[2], &pt_len_2);
    clock_t start, end;

    // Operations is roughly equivalent to (n^2)/2
    start = clock();
    bruteInversionCount(int_array, int_len, &inversions, &operations);
    end = clock();
    printf("Finished 1.1 in %.2lf seconds.\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("Inversions: %d, Operations: %d\n", inversions, operations);

    inversions = 0;
    operations = 0;

    // Operations is roughly equivalent to 3n*log(n)
    start = clock();
    divideInversionCount(int_array, int_len, &inversions, &operations);
    end = clock();
    printf("Finished 1.2 in %.3lf seconds.\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("Inversions: %d, Operations: %d\n", inversions, operations);

    operations = 0;

    start = clock();
    bruteHull(pt_array, pt_len, &operations);
    end = clock();
    printf("Operations: %d\n", operations);
    printf("Finished 2.1 in %.4lf seconds.\n", (double)(end - start) / CLOCKS_PER_SEC);

    operations = 0;

    start = clock();
    fastHull(pt_array_2, pt_len_2, &operations);
    end = clock();
    printf("Operations: %d\n", operations);
    printf("Finished 2.2 in %.4lf seconds.\n", (double)(end - start) / CLOCKS_PER_SEC);

    if (int_array)
        free(int_array);
    if (pt_array)
        free(pt_array);

    return 0;
}