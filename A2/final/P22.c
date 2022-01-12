#include "Helpers.h"
#include "P2.h"

/**
 * @brief Assignment 2
 * @author Conor Roberts (#1056167)
 * @date February 22nd, 2021
 * 
 */


/**
 * @brief 
 * 
 * @param arr 
 * @param len 
 * @param operations 
 */
void fastHull(Point *arr, int len, int *operations)
{
    if (len < 3)
    {
        printf("No convex hull possible with < 3 points.\n");
        return;
    }

    qsort(arr, len, sizeof(Point), comparX);
    Point left = arr[0];
    Point right = arr[len - 1];

    // Find leftmost point
    Point above[len], below[len], result[len];
    int n_above = 0, n_below = 0, n_result = 0;

    for (int i = 0; i < len; i++)
    {
        double val = checkSide(left, right, arr[i]);
        (*operations)++;
        if (val < 0)
            above[n_above++] = arr[i];
        else if (val > 0)
            below[n_below++] = arr[i];
    }

    fastHull2(above, n_above, left, right, result, &n_result, operations);
    fastHull2(below, n_below, right, left, result, &n_result, operations);

    qsort(result, n_result, sizeof(Point), comparX);
    trimList(result, &n_result);
    printPoints(result, n_result);
}

/**
 * @brief 
 * 
 * @param arr 
 * @param len 
 * @param left 
 * @param right 
 * @param result 
 * @param count 
 * @param operations 
 */
void fastHull2(Point *arr, int len, Point left, Point right, Point *result, int *count, int *operations)
{
    if (!arr || len == 0)
        return;

    double max = 0;
    int max_index = -1;

    for (int i = 0; i < len; i++)
    {
        // Find out whether the point is above or below our line
        double res = checkSide(left, right, arr[i]);

        // Check that it's a greate value than our previous max
        if (checkSide(left, right, arr[i]) < 0 && res < max)
        {
            max_index = i;
            max = res;
        }
    }

    // Check if the index has changed at all ebfore updating it
    if (max_index == -1)
    {
        // Make sure the item isn't already within the array
        // If not then in the default case, we are just going to add the endpoints
        if (arrayIncludes(result, *count, left) == -1)
            result[(*count)++] = left;

        if (arrayIncludes(result, *count, right) == -1)
            result[(*count)++] = right;

        return;
    }

    // Recursive call
    fastHull2(arr, len, left, arr[max_index], result, count, operations);
    fastHull2(arr, len, arr[max_index], right, result, count, operations);
}
