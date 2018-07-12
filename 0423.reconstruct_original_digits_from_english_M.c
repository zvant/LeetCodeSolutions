/**
 * https://leetcode.com/problems/reconstruct-original-digits-from-english/description/
 * 2016/11
 * 6 ms
 */

char * originalDigits(char * s)
{
    int letter_counts[1 + 'z'] = {0};
    int num_counts[10] = {0};
    char * p;
    for(p = s; '\0' != * p; p ++)
    {
        letter_counts[* p] ++;
    }
    
    num_counts[0] = letter_counts['z'];
    num_counts[2] = letter_counts['w'];
    num_counts[4] = letter_counts['u'];
    num_counts[6] = letter_counts['x'];
    num_counts[8] = letter_counts['g'];
    num_counts[3] = letter_counts['h'] - num_counts[8];
    num_counts[5] = letter_counts['f'] - num_counts[4];
    num_counts[7] = letter_counts['v'] - num_counts[5];
    num_counts[1] = letter_counts['o'] - num_counts[0] - num_counts[2] - num_counts[4];
    num_counts[9] = letter_counts['i'] - num_counts[5] - num_counts[6] - num_counts[8];
    
    size_t len = 0;
    for(int idx = 0; idx < 10; idx ++)
    {
        len += num_counts[idx];
    }
    char * result = (char *)malloc(len + 1);
    result[len] = '\0';
    
    p = result;
    for(char num = 0; num < 10; num ++)
    {
        memset(p, '0' + num, num_counts[num]);
        p += num_counts[num];
    }
    return result;
}
