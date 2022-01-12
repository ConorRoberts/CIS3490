#include "Helpers.h"

int P23(StringStorage *store)
{
    char pattern[LINE_LENGTH];
    printf("(P23) Enter a pattern: ");
    scanf("%s", pattern);

    int n_matches = 0, shifts = 0;
    int len_pattern = strlen(pattern);

    for (int i = 0; i < store->n; i++)
    {
        String str = store->strings[i];
        int len_string = strlen(str.string);

        int badchar[LINE_LENGTH];

        badCharTable(pattern, len_pattern, badchar);

        for (int tmp_shift = 0; tmp_shift <= (len_string - len_pattern);)
        {
            int index;

            // Decrement the index
            for (index = len_pattern - 1; index >= 0 && (pattern[index] == str.string[tmp_shift + index]); index--)
                ;

            if (index < 0)
            {
                shifts += tmp_shift;
                n_matches++;

                int tmp = tmp_shift + len_pattern;
                if (tmp < len_string)
                    tmp_shift += len_pattern - badchar[str.string[tmp_shift + len_pattern]];
                else
                    tmp_shift += 1;
            }
            else
            {
                int tmp = index - badchar[str.string[tmp_shift + index]];
                tmp_shift += 1 > tmp ? 1 : tmp;
            }
        }
    }

    printf("Shifted %d times\n", shifts);

    return n_matches;
}
