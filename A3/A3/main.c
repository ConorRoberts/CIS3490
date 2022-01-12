#include "Helpers.h"

/**
 * 
 * @brief Assignment 2
 * @author Conor Roberts (#1056167)
 * @date March 15, 2021
 */

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage Error - Usage: ./main <p1_file.txt> <p2_file.txt>\n");
        return 1;
    }

    clock_t start, end;
    int n_anagrams = 0, n_matches = 0;

    StringStorage *p1 = createStringStorage(argv[1]);
    StringStorage *p2 = createLineStorage(argv[2]);

    // P11
    start = clock();
    n_anagrams = P11(p1);
    end = clock();
    printf("Found %d anagrams in %.4lfs\n", n_anagrams, getSeconds(start, end));

    // P12
    start = clock();
    qsort(p1->strings, p1->n, sizeof(String), stringListCompare);
    end = clock();
    printf("Sorted %d strings in %.4lfs\n", p1->n, getSeconds(start, end));

    start = clock();
    n_anagrams = P12(p1);
    end = clock();
    printf("Found %d anagrams in %.4lfs\n", n_anagrams, getSeconds(start, end));

    // P21
    start = clock();
    n_matches = P21(p2);
    end = clock();
    printf("Found %d matches in time %.4lfs\n", n_matches, getSeconds(start, end));

    // P22
    start = clock();
    n_matches = P22(p2);
    end = clock();
    printf("Found %d matches in time %.4lfs\n", n_matches, getSeconds(start, end));

    // P23
    start = clock();
    n_matches = P23(p2);
    end = clock();
    printf("Found %d matches in time %.4lfs\n", n_matches, getSeconds(start, end));

    freeStringStorage(p1);
    freeStringStorage(p2);

    return 0;
}