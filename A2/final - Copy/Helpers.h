#ifndef _HELPERS_H_
#define _HELPERS_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/**
 * @brief Assignment 2
 * @author Conor Roberts (#1056167)
 * @date February 22nd, 2021
 * 
 */


#define LINE_LENGTH 256

typedef struct
{
    double x, y;
} Point;

// Data parsing
int *intArrayFromFile(char *name, int *len);
Point *pointArrayFromFile(char *name, int *len);

// P1
int *arraySlice(int *arr, int len, int start, int end);
void merge(int *A, int A_len, int *B, int B_len, int *C, int C_len, int *inversions, int *operations);
void printArray(int *arr, int len);
void appendSlice(int *arr, int arr_start, int *new, int new_len, int new_start);

// P2
void printPoints(Point *arr, int len);
double checkSide(Point a, Point b, Point c);
int arrayIncludes(Point *arr, int len, Point p);
int comparX(const void *a, const void *b);
void trimList(Point *arr, int *len);

#endif