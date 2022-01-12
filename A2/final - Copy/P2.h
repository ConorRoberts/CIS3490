#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Helpers.h"

/**
 * @brief Assignment 2
 * @author Conor Roberts (#1056167)
 * @date February 22nd, 2021
 * 
 */


void bruteHull(Point *arr, int len, int *operations);

void fastHull(Point *arr, int len, int *operations);

void fastHull2(Point *arr, int len, Point left, Point right, Point *result, int *count, int *operations);
