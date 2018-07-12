/**
 * https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/
 * 2016/10
 * 0 ms
 */

char * toHex(int num)
{
    char * hex_str = NULL;
    if(num == 0)
    {
        hex_str = (char *)malloc(sizeof(char) * 2);
        snprintf(hex_str, 2, "0");
        return hex_str;
    }
    const char * hex_chars = "0123456789abcdef";
    int mask = 15;
    char hex_bits[8];
    for(int shift = 0; shift < 8; shift ++)
    {
        hex_bits[shift] = hex_chars[mask & (num >> (4 * shift))];
    }
    int idx;
    for(idx = 7; idx >= 0; idx --)
    {
        if(hex_bits[idx] != '0')
            break;
    }
    int len = idx + 1;
    hex_str = (char *)malloc(sizeof(char) * (len + 1));
    hex_str[len] = '\0';
    for(int bit = 0; bit < len; bit ++)
    {
        hex_str[bit] = hex_bits[idx];
        idx --;
    }
    return hex_str;
}
