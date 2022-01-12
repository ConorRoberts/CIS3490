#include "Helpers.h"

int P21(StringStorage *store)
{
    char str[LINE_LENGTH];
    printf("(P21) Enter a string: ");
    scanf("%s", str);

    int n_matches = 0, shifts = 0;

    for (int i = 0; i < store->n; i++)
    {
        String s = store->strings[i];
        int len = strlen(s.string);

        int j = 0;
        for (int j = 0; j < len; j++)
        {
            char *slice = stringSlice(s.string, j, len);
            shifts++;

            if (strncmp(slice, str, strlen(str)) == 0)
            {
                n_matches++;
                j += strlen(str);
            }

            free(slice);
        }
    }

    printf("Shifted %d times\n",shifts);

    return n_matches;
}
