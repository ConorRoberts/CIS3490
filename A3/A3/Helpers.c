#include "Helpers.h"

/**
 * 
 * @brief Assignment 2
 * @author Conor Roberts (#1056167)
 * @date March 15, 2021
 */

double getSeconds(clock_t start, clock_t end)
{
    double sec = (double)(end - start) / CLOCKS_PER_SEC;
    return sec;
}

StringStorage *createStringStorage(char *name)
{
    FILE *fp = NULL;

    // Check for valid file
    if ((fp = fopen(name, "r")) == NULL)
    {
        fprintf(stderr, "Error - Could not open file '%s'.\n", name);
        exit(0);
    }

    // Variables
    char line[LINE_LENGTH];
    char *token;
    const char s[2] = " ";

    // Initialize the string store
    StringStorage *store = (StringStorage *)malloc(sizeof(StringStorage));
    store->n = 0;

    // Load data into array
    while (fgets(line, LINE_LENGTH, fp) != NULL)
    {
        // Splits up line garbage into array stored in argv
        strtok(line, "\n");
        token = strtok(line, s);

        while (token != NULL)
        {
            // Decide how to allocate the memory for this iteration
            if (store->n == 0)
                store->strings = (String *)malloc(sizeof(String));
            else
                store->strings = (String *)realloc(store->strings, sizeof(String) * (store->n + 1));

            // Allocate for a string, assign the string
            store->strings[store->n].string = (char *)malloc(LINE_LENGTH);
            strcpy(store->strings[store->n].string, token);

            // Sorted version
            store->strings[store->n].sorted = sortString(store->strings[store->n].string);

            // Increment length
            store->n++;

            token = strtok(NULL, s);
        }
    }

    if (fp)
        fclose(fp);

    return store;
}

StringStorage *createLineStorage(char *name)
{
    FILE *fp = NULL;

    // Check for valid file
    if ((fp = fopen(name, "r")) == NULL)
    {
        fprintf(stderr, "Error - Could not open file '%s'.\n", name);
        exit(0);
    }

    // Variables
    char line[LINE_LENGTH];

    // Initialize the string store
    StringStorage *store = (StringStorage *)malloc(sizeof(StringStorage));
    store->n = 0;

    // Load data into array
    while (fgets(line, LINE_LENGTH, fp) != NULL)
    {
        // Splits up line garbage into array stored in argv
        strtok(line, "\n");

        if (store->n == 0)
            store->strings = (String *)malloc(sizeof(String));
        else
            store->strings = (String *)realloc(store->strings, sizeof(String) * (store->n + 1));

        // Allocate for a string, assign the string
        store->strings[store->n].string = (char *)malloc(LINE_LENGTH);
        strcpy(store->strings[store->n].string, line);

        // Sorted version
        store->strings[store->n].sorted = sortString(store->strings[store->n].string);

        // Increment length
        store->n++;
    }

    if (fp)
        fclose(fp);

    return store;
}

void freeStringStorage(StringStorage *store)
{
    if (store == NULL || store->strings == NULL)
        return;

    for (int i = 0; i < store->n; i++)
    {
        free(store->strings[i].string);
        free(store->strings[i].sorted);
    }

    free(store->strings);
    free(store);
}
void printStringStorage(StringStorage *store)
{
    if (store == NULL)
        return;

    for (int i = 0; i < store->n; i++)
        printf("%s %s \n", store->strings[i].string, store->strings[i].sorted);
}

int charCompare(const void *a, const void *b)
{
    const char *c1 = (const char *)a; // casting pointer types
    const char *c2 = (const char *)b;
    return *c1 - *c2;
}

char *sortString(char *str)
{
    char *sorted_str = (char *)malloc(strlen(str) + 1);
    strcpy(sorted_str, str);
    qsort(sorted_str, strlen(str), sizeof(char), charCompare);
    return sorted_str;
}

int stringListCompare(const void *a, const void *b)
{
    String *s1 = (String *)a;
    String *s2 = (String *)b;
    return (strcmp(s1->sorted, s2->sorted));
}

int binarySearch(StringStorage *store, int l, int r, char *target)
{
    if (r >= l)
    {
        int m = l + (r - l) / 2;

        if (strcmp(store->strings[m].sorted, target) == 0)
            return m;

        if (strcmp(store->strings[m].sorted, target) > 0)
            return binarySearch(store, l, m - 1, target);

        return binarySearch(store, m + 1, r, target);
    }

    return -1;
}

char *stringSlice(char *s, int start, int end)
{
    int slice_length = end - start;
    char *sliced = (char *)malloc(slice_length);

    int c = 0;

    for (int i = start; i < end; i++)
        sliced[c++] = s[i];

    return sliced;
}

void initShiftTable(int *table, int len, char *pattern)
{
    int m = strlen(pattern);

    for (int i = 0; i < len; i++)
        table[i] = m;

    for (int i = 0; i < m - 1; i++)
    {
        table[pattern[i]] = m - 1 - i;
    }
}

int horspool(char *text, char *pattern, int *table, int *shift, int index)
{
    int len_text = strlen(text);
    int len_pattern = strlen(pattern);
    int i, k;

    // Do some wizard magic
    for (int i = index + len_pattern - 1; i < len_text; i += table[text[i]])
    {
        for (k = 0; (k < len_pattern) && (pattern[len_pattern - 1 - k] == text[i - k]); k++)
            ;

        (*shift) += k;

        if (k == len_pattern)
            return (i - len_pattern + 1);
    }
    return -1;
}

void badCharTable(char *str, int len_pattern, int *badchar)
{
    for (int i = 0; i < LINE_LENGTH; i++)
        badchar[i] = -1;

    for (int i = 0; i < len_pattern; i++)
        badchar[str[i]] = i;
}