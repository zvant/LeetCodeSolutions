/**
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 * 2016/05
 * 4 ms
 */

#define IS_NOT_VOWEL(c) \
( \
    'A' != c && \
    'E' != c && \
    'I' != c && \
    'O' != c && \
    'U' != c && \
    'a' != c && \
    'e' != c && \
    'i' != c && \
    'o' != c && \
    'u' != c \
)

char * reverseVowels(char * s)
{
    int len = strlen(s);
    char * reversed = (char *)malloc(len + 1);
    strncpy(reversed, s, len);
    reversed[len] = '\0';
    
    int left = 0;
    int right = len - 1;
    
    while(true)
    {
        while(left < len && IS_NOT_VOWEL(reversed[left]))
            left ++;
        while(right >= 0 && IS_NOT_VOWEL(reversed[right]))
            right --;
        if(left >= right)
            break;
        char tmp = reversed[left];
        reversed[left] = reversed[right];
        reversed[right] = tmp;
        left ++;
        right --;
    }
    
    return reversed;
}
