#include "Helpers.h"

int P22(StringStorage *store)
{
    char pattern[LINE_LENGTH];
    printf("(P22) Enter a pattern: ");
    scanf("%s", pattern);

    int table[LINE_LENGTH];
    int n_matches = 0, shifts = 0;
    initShiftTable(table,LINE_LENGTH, pattern);

    for (int i = 0; i < store->n; i++)
    {
        String s = store->strings[i];
        int index = 0;
        while((index=horspool(s.string, pattern, table, &shifts, index))!=-1){
            n_matches++;
            index++;
        }
    }

    printf("Shifted %d times\n",shifts);

    return n_matches;
}
