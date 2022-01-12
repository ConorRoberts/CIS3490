#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "P1.h"
#include "P2.h"
#include "Helpers.h"

#define LINE_LENGTH 256

int main(int argc, char *argv[])
{
    int int_len = 0, dbl_len = 0, inversions = 0, operations = 0;

    int *int_array = intArrayFromFile(argv[1], &int_len);
    // double *dbl_array = dblArrayFromFile(argv[2], &dbl_len);
    clock_t start, end;

    start = clock();
    // Operations is roughly equivalent to (n^2)/2
    bruteInversionCount(int_array, int_len, &inversions, &operations);
    end = clock();
    printf("Finished 1.1 in %.2lf seconds.\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("Inversions: %d, Operations: %d\n", inversions, operations);

    inversions = 0;
    operations = 0;

    start = clock();
    // Operations is roughly equivalent to 3n*log(n)
    divideInversionCount(int_array, int_len, &inversions, &operations);
    end = clock();
    printf("Finished 1.2 in %.3lf seconds.\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("Inversions: %d, Operations: %d\n", inversions, operations);

    if (int_array)
        free(int_array);
    // if (dbl_array)
    //     free(dbl_array);

    return 0;
}