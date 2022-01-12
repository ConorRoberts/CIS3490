#include "Helpers.h"
#include "P2.h"

/**
 * @brief Assignment 2
 * @author Conor Roberts (#1056167)
 * @date February 22nd, 2021
 * 
 */


int *intArrayFromFile(char *name, int *len)
{
    FILE *fp = NULL;
    char line[LINE_LENGTH];

    // Check for valid file
    if ((fp = fopen(name, "r")) == NULL)
    {
        fprintf(stderr, "Error - Could not open file '%s'.\n", name);
        exit(0);
    }

    // Variables
    char *token;
    const char s[2] = " ";
    int inputArrayLength = 0;
    int *inputArray = (int *)malloc(sizeof(int));

    // Load data into array
    while (fgets(line, LINE_LENGTH, fp) != NULL)
    {
        // Splits up line garbage into array stored in argv
        strtok(line, "\n");
        token = strtok(line, s);
        while (token != NULL)
        {
            if (inputArrayLength > 0)
            {
                inputArray = (int *)realloc(inputArray, sizeof(int) * (inputArrayLength + 1));
            }
            inputArray[inputArrayLength++] = atoi(token);

            token = strtok(NULL, s);
        }
    }

    *len = inputArrayLength;

    if (fp)
        fclose(fp);

    return inputArray;
}

Point *pointArrayFromFile(char *name, int *len)
{
    FILE *fp = NULL;
    char line[LINE_LENGTH];

    // Check for valid file
    if ((fp = fopen(name, "r")) == NULL)
    {
        fprintf(stderr, "Error - Could not open file '%s'.\n", name);
        exit(0);
    }

    // Variables
    char *token;
    const char s[2] = " ";
    int inputArrayLength = 0;
    Point *inputArray = (Point *)malloc(sizeof(Point));

    // Load data into array
    while (fgets(line, LINE_LENGTH, fp) != NULL)
    {
        // Splits up line garbage into array stored in argv
        int count = 0;
        Point point;
        if (inputArrayLength > 0)
        {
            inputArray = (Point *)realloc(inputArray, sizeof(Point) * (inputArrayLength + 1));
        }

        strtok(line, "\n");
        token = strtok(line, s);

        while (token != NULL)
        {
            if (count == 0)
                point.x = atof(token);
            else
                point.y = atof(token);

            count++;

            token = strtok(NULL, s);
        }

        // Append new point to array
        inputArray[inputArrayLength++] = point;
    }

    *len = inputArrayLength;

    if (fp)
        fclose(fp);

    return inputArray;
}

void printPoints(Point *arr, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d.\t(%10.1lf, %10.1lf)\n", i + 1, arr[i].x, arr[i].y);
    printf("Found convex hull with %d points\n", len);
}

/**
 * @brief Checks if a point is above or below the line made by a->b
 * 
 * @param a Left
 * @param b Right
 * @param c Point to compare
 * @return double 
 */
double checkSide(Point a, Point b, Point c)
{
    return (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
}

/**
 * @brief Returns found index of Point in array
 * 
 * @param arr 
 * @param len 
 * @param p 
 * @return int 
 */
int arrayIncludes(Point *arr, int len, Point p)
{
    for (int i = 0; i < len; i++)
        if (arr[i].x == p.x && arr[i].y == p.y)
            return i;

    return -1;
}

/**
 * @brief Compares two points by x value
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int comparX(const void *a, const void *b)
{
    Point *pt_a = (Point *)a;
    Point *pt_b = (Point *)b;

    double a_x = (double)pt_a->x;
    double b_x = (double)pt_b->x;

    double a_y = (double)pt_a->y;
    double b_y = (double)pt_b->y;

    if (a_x > b_x)
    {
        return 1;
    }
    else if (a_x < b_x)
    {
        return -1;
    }

    // Comparing x was a tie
    if (a_y > b_y)
    {
        return 1;
    }
    else if (a_y < b_y)
    {
        return -1;
    }

    // Points must be equal
    return 0;
}

/**
 * @brief Merges B,C, into A
 * 
 * @param A Original array
 * @param A_len Length of original array
 * @param B Array representing the lower half 
 * @param B_len Length of lower half
 * @param C Array representing upper half
 * @param C_len Length of upper half
 * @param inversions Count of inversions
 * @param operations Count of operations
 */
void merge(int *A, int A_len, int *B, int B_len, int *C, int C_len, int *inversions, int *operations)
{
    int a = 0, b = 0, c = 0;

    while (b < B_len && c < C_len)
    {
        (*operations)++;
        if (B[b] <= C[c])
        {
            A[a] = B[b++];
        }
        else
        {
            A[a] = C[c++];
            (*inversions) += B_len - b;
        }
        a++;
    }

    if (b == B_len)
    {
        appendSlice(A, a, C, C_len, c);
    }
    else
    {
        appendSlice(A, a, B, B_len, b);
    }
}

/**
 * @brief Prints array of integers
 * 
 * @param arr Array of integers
 * @param len Length of array
 */
void printArray(int *arr, int len)
{
    if (!arr)
        return;

    for (int i = 0; i < len; i++)
        printf("[%d]: %d\n", i, arr[i]);
}

/**
 * @brief Returns a slice of arr from index start to end
 * 
 * @param arr Original array
 * @param len Length of original array
 * @param start Start index of slice
 * @param end End index of slice
 * @return int* Sliced array
 */
int *arraySlice(int *arr, int len, int start, int end)
{
    int slice_length = end - start;
    int *sliced = (int *)malloc(sizeof(int) * slice_length);

    int c = 0;

    for (int b = start; b < end; b++)
        sliced[c++] = arr[b];

    return sliced;
}

/**
 * @brief Appends a new array to the original starting at 'start'
 * 
 * @param arr Original array
 * @param arr_start Starting index within arr
 * @param new Array to be copied from
 * @param new_len Length of new array
 * @param new_start Starting index within new
 */
void appendSlice(int *arr, int arr_start, int *new, int new_len, int new_start)
{
    for (int i = new_start; i < new_len; i++)
        arr[arr_start++] = new[i];
}

/**
 * @brief Trims the garbage within the list (probably collinear points)
 * 
 * @param arr The array... lmaoo..
 * @param len The length of the array
 */
void trimList(Point *arr, int *len)
{
    for (int i = 0; i < *len; i++)
    {
        int n = 0;
        int index_first = -1;
        int index_last = -1;

        // Counts occurrences
        for (int j = 0; j < *len; j++)
        {
            if (arr[j].x == arr[i].x)
            {
                n++;
                if (index_first == -1)
                    index_first = j;
            }
        }

        // Case that we need to filter some elements
        if (n > 2)
        {
            // Finds latest occurence of value
            for (int j = *len - 1; j >= 0; j--)
            {
                if (arr[j].x == arr[i].x)
                {
                    index_last = j;
                    break;
                }
            }
            // Now we have upper and lower index, just have to eliminate middle elements
            // start at index_first+1
            // index_first+2 = result[index_last]
            int k = 0;
            *len -= n - 2;
            for (int j = index_first + 1; j < *len; j++)
            {
                arr[j] = arr[index_last + (k++)];
            }
        }
    }
}