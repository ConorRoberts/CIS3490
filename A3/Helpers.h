#ifndef _HELPERS_H_
#define _HELPERS_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

/**
 * 
 * @brief Assignment 2
 * @author Conor Roberts (#1056167)
 * @date March 15, 2021
 */

#define LINE_LENGTH 500

typedef struct{
    // The original string
    char *string;

    // Original string with characters sorted
    char *sorted;
}String;

typedef struct{
    int n;
    String *strings;
} StringStorage;

// Assignment

/**
 * @brief 
 * 
 * @param store 
 * @return int 
 */
int P11(StringStorage *store);

/**
 * @brief 
 * 
 * @param store 
 * @return int 
 */
int P12(StringStorage *store);

/**
 * @brief 
 * 
 * @param store 
 * @return int 
 */
int P21(StringStorage *store);

/**
 * @brief Horspool 
 * 
 * @param store 
 * @return int 
 */
int P22(StringStorage *store);

/**
 * @brief 
 * 
 * @param store 
 * @return int 
 */
int P23(StringStorage *store);

// Helpers
/**
 * @brief Get the Seconds object
 * 
 * @param start 
 * @param end 
 * @return double 
 */
double getSeconds(clock_t start, clock_t end);

/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int charCompare(const void *a, const void *b);

/**
 * @brief 
 * 
 * @param str 
 * @return char* 
 */
char *sortString(char *str);

/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int stringListCompare(const void *a, const void *b);

/**
 * @brief 
 * 
 * @param store 
 * @param l 
 * @param r 
 * @param target 
 * @return int 
 */
int binarySearch(StringStorage *store, int l, int r, char *target);

/**
 * @brief 
 * 
 * @param s 
 * @param start 
 * @param end 
 * @return char* 
 */
char *stringSlice(char *s, int start, int end);

/**
 * @brief 
 * 
 * @param table 
 */
void initShiftTable(int *table, int len, char *str);

/**
 * @brief 
 * 
 * @param src 
 * @param p 
 * @param t 
 * @return int 
 */
int horspool(char *src, char p[], int *t, int *s, int index);

/**
 * @brief 
 * 
 * @param str 
 * @param len_pattern 
 * @param badchar 
 */
void badCharTable(char *str, int len_pattern, int *badchar);

// Struct methods
/**
 * @brief Create a String Storage object
 * 
 * @param name 
 * @return StringStorage* 
 */
StringStorage *createStringStorage(char *name);

/**
 * @brief Create a Line Storage object
 * 
 * @param name 
 * @return StringStorage* 
 */
StringStorage *createLineStorage(char *name);

/**
 * @brief 
 * 
 * @param store 
 */
void printStringStorage(StringStorage *store);

/**
 * @brief 
 * 
 * @param store 
 */
void freeStringStorage(StringStorage *store);

#endif