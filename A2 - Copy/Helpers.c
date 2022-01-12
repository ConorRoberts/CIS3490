#include "Helpers.h"

int *intArrayFromFile(char *name,int *len){
    FILE *fp = NULL;
    char line[LINE_LENGTH];

    // Check for valid file
    if ((fp = fopen(name, "r")) == NULL){
        fprintf(stderr,"Error - Could not open file '%s'.\n",name);
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
        strtok(line,"\n");
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

    *len=inputArrayLength;

     if (fp)
        fclose(fp);

    return inputArray;
}

double *dblArrayFromFile(char *name,int *len){
    FILE *fp = NULL;
    char line[LINE_LENGTH];

    // Check for valid file
    if ((fp = fopen(name, "r")) == NULL){
        fprintf(stderr,"Error - Could not open file '%s'.\n",name);
        exit(0);
    }

    // Variables
    char *token;
    const char s[2] = " ";
    int inputArrayLength = 0;
    double *inputArray = (double *)malloc(sizeof(double));

    // Load data into array
    while (fgets(line, LINE_LENGTH, fp) != NULL)
    {
        // Splits up line garbage into array stored in argv
        strtok(line,"\n");
        token = strtok(line, s);
        while (token != NULL)
        {   
            if (inputArrayLength > 0)
            {
                inputArray = (double *)realloc(inputArray, sizeof(double) * (inputArrayLength + 1));
            }
            inputArray[inputArrayLength++] = atof(token);

            token = strtok(NULL, s);
        }
    }

    *len=inputArrayLength;

     if (fp)
        fclose(fp);

    return inputArray;
}

