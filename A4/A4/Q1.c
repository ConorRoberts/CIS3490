#include "Helpers.h"

/**
 * @author Conor Roberts (#1056167)
 * @brief CIS3490 Assignment 4
 * @date 2021-03-27
 * 
 */

int main(int argc, char *argv[])
{
    Strings *strings = create_strings(argv[1]);
    qsort(strings->words, strings->size, sizeof(Word), compare);

    int n = strings->size + 2;
    int **R = (int **)calloc(1, sizeof(int *) * n);
    float **C = (float **)calloc(1, sizeof(float *) * n);

    for (int i = 0; i < n; i++)
    {
        R[i] = (int *)calloc(1, sizeof(int) * n);
        C[i] = (float *)calloc(1, sizeof(float) * n);
    }

    create_bst(strings, R, C);
    char key[LINE_LENGTH];
    printf("Enter a key: ");
    scanf("%s", key);

    search(strings, 1, strings->size, R, C, key);

    free_strings(strings);
    for (int i = 0; i < n; i++)
    {
        free(R[i]);
        free(C[i]);
    }

    free(R);
    free(C);

    return 0;
}