#ifndef _HELPERS_H_
#define _HELPERS_H_

/**
 * @author Conor Roberts (#1056167)
 * @brief CIS3490 Assignment 4
 * @date 2021-03-27
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 512

typedef struct{
    char *word;
    int count;
    float prob;
}Word;

typedef struct
{
    Word *words;
    int size;
} Strings;

Strings *create_strings(char *file_name);
void free_strings(Strings *str);
void create_bst(Strings *str, int **R, float **C);
int compare (const void *a, const void *b);
void search(Strings *strings, int row, int col, int **R, float **C, char *key);

#endif