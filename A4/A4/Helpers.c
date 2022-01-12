#include "Helpers.h"
/**
 * @author Conor Roberts (#1056167)
 * @brief CIS3490 Assignment 4
 * @date 2021-03-27
 * 
 */

Strings *create_strings(char *file_name)
{
    FILE *fp = fopen(file_name, "r+");
    if (fp == NULL)
        return NULL;

    char line[LINE_LENGTH];
    Strings *str = (Strings *)malloc(sizeof(Strings));
    str->words = (Word *)malloc(sizeof(Word));

    char *token;
    const char s[2] = " ";

    for (str->size = 0; fgets(line, LINE_LENGTH, fp) != NULL;)
    {
        strtok(line, "\n");
        token = strtok(line, s);

        while (token != NULL)
        {
            int contains = 0;
            for (int j = 0; j < str->size && contains == 0; j++)
            {
                if (strcmp(str->words[j].word, token) == 0)
                {
                    contains = 1;
                    str->words[j].count++;
                }
            }

            // New unique word found
            if (contains == 0)
            {
                if (str->size > 0)
                    str->words = realloc(str->words, sizeof(Word) * (str->size + 1));
                str->words[str->size].word = (char *)malloc(strlen(token) + 2);
                str->words[str->size].count = 1;
                str->words[str->size].prob = 0;
                strcpy(str->words[str->size++].word, token);
            }

            token = strtok(NULL, s);
        }
    }

    int sum = 0;
    for (int i = 0; i < str->size; i++)
        sum += str->words[i].count;

    for (int i = 0; i < str->size; i++)
        str->words[i].prob = str->words[i].count / (float)sum;

    fclose(fp);

    return str;
}

void free_strings(Strings *str)
{
    for (int i = 0; i < str->size; i++)
        free(str->words[i].word);

    free(str->words);
    free(str);
}

void create_bst(Strings *str, int **R, float **C)
{
    int n = str->size;
    for (int i = 1; i <= n; i++)
    {
        C[i][i - 1] = 0;
        C[i][i] = str->words[i - 1].prob;
        R[i][i] = i;
    }
    C[n + 1][n] = 0;
    for (int d = 1; d <= n - 1; d++)
    {
        for (int i = 1; i <= n - d; i++)
        {
            int j = i + d;
            float minval = __INT_MAX__;
            int kmin = __INT_MAX__;
            for (int k = i; k <= j; k++)
            {
                if (C[i][k - 1] + C[k + 1][j] < minval)
                {
                    minval = C[i][k - 1] + C[k + 1][j];
                    kmin = k;
                }
            }
            R[i][j] = kmin;
            float sum = str->words[i-1].prob;
            for (int s = i + 1; s <= j; s++)
                sum += str->words[s-1].prob;
            C[i][j] = minval + sum;
        }
    }
}

int compare(const void *a, const void *b)
{
    Word *w1 = (Word *)a;
    Word *w2 = (Word *)b;

    return strcmp(w1->word,w2->word);
}

void search(Strings *strings, int row, int col, int **R, float **C, char *key)
{
    int word_index = R[row][col];
    char *word = strings->words[word_index].word;
    int cmp = strcmp(key, word);

    if (cmp < 0)
    {
        printf("Compared with '%s' (%3.2f), go left\n", word, C[row][col]);
        if (col - 1 <=0)
            printf("Not found\n");
        else
            search(strings, row, col - 1, R, C, key);
    }
    else if (cmp > 0)
    {
        printf("Compared with '%s' (%3.2f), go right\n", word, C[row][col]);
        if (row + 1 >= strings->size)
            printf("Not found\n");
        else
            search(strings, row + 1, col, R, C, key);
    }
    else
    {
        printf("Compared with '%s' (%3.2f), found\n", word, C[row][col]);
    }
}
