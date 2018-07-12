/**
 * https://leetcode.com/problems/maximum-product-of-word-lengths/description/
 * 2016/07
 * 68 ms
 */

#include <stdint.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

struct Word
{ // only lower-case
    char * str;
    int len;
    uint32_t i;
};

int compare_len(const void * w1, const void * w2)
{
    return ((struct Word *)w1) -> len - ((struct Word *)w2) -> len;
}

int maxProduct(char** words, int wordsSize)
{
    int idx;
    struct Word * words_rep = (struct Word *)malloc(sizeof(struct Word) * wordsSize);
    for(idx = 0; idx < wordsSize; idx ++)
    {
        words_rep[idx].str = words[idx];
        words_rep[idx].len = strlen(words[idx]);
        words_rep[idx].i = 0;
        char * strp;
        for(strp = words[idx]; '\0' != * strp; strp ++)
            words_rep[idx].i |= (uint32_t)1 << (* strp - 'a');
    }
    qsort(words_rep, wordsSize, sizeof(struct Word), compare_len);
    int idx1, idx2;
    int max_prod = 0;
    for(idx1 = wordsSize - 1; idx1 >= 0; idx1 --)
    {
        for(idx2 = idx1 - 1; idx2 >= 0; idx2 --)
        {
            if(0 == (words_rep[idx1].i & words_rep[idx2].i))
            {
                int prod = words_rep[idx1].len * words_rep[idx2].len;
                if(prod > max_prod)
                    max_prod = prod;
            }
        }
    }
    return max_prod;
}
