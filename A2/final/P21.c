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
void bruteHull(Point *arr, int len, int *operations)
{
    Point result[len];
    int count = 0;

    // Meant to find extreme points
    for (int i = 0; i < len; i++)
    {
        // int uses = 0;
        for (int j = 0; j < len; j++)
        {
            // Count for each side of the line defined by arr[i] and arr[j]
            int s1 = 0, s2 = 0;

            // Checks the side of each point
            for (int k = 0; k < len; k++)
            {
                (*operations)++;
                int val = checkSide(arr[i], arr[j], arr[k]);
                if (val >0 )
                    s1++;
                else if (val <0)
                    s2++;

                // If both sides have points this is obviously not a contender
                if (s1 && s2)
                    break;
            }

            // Have to ensure that this is not a duplicate and only 1/2 sides has points
            if ((!s1) != (!s2) && arrayIncludes(result, count, arr[i]) == -1)
                result[count++] = arr[i];
        }
    }

    qsort(result, count, sizeof(Point), comparX);
    trimList(result,&count);

    printPoints(result, count);
}