#include "Helpers.h"

/**
 * 
 * @brief Assignment 2
 * @author Conor Roberts (#1056167)
 * @date March 15, 2021
 */

int P11(StringStorage *store)
{
    char str[LINE_LENGTH];
    printf("(P11) Enter a string: ");
    scanf("%s", str);

    char *sorted_str = sortString(str);
    int n_anagrams = 0;

    for (int i = 0; i < store->n; i++)
    {
        if (strcmp(sorted_str, store->strings[i].sorted) == 0 && strcmp(store->strings[i].string, str) != 0)
        {
            printf("\"%s\" is an anagram of \"%s\"\n", store->strings[i].string, str);
            n_anagrams++;
        }
    }

    free(sorted_str);

    return n_anagrams;
}