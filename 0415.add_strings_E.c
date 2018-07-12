/**
 * https://leetcode.com/problems/add-strings/description/
 * 2016/10
 * 3 ms
 */

char * addStrings(char * num1, char * num2)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int max_len = (len1 > len2) ? len1 : len2;
    int min_len = (len1 < len2) ? len1 : len2;
    char * sum = (char *)malloc(sizeof(char) * (max_len + 2));
    int bit;
    char carry = 0;
    for(bit = 0; bit < min_len; bit ++)
    {
        char add = num1[len1 - bit - 1] - '0' + num2[len2 - bit - 1] - '0' + carry;
        sum[bit] = (add % 10) + '0';
        carry = add / 10;
    }
    if(len1 == len2)
    {
        sum[bit] = carry + '0';
    }
    else
    {
        char * remain = (len1 > len2) ? num1 : num2;
        for(; bit < max_len; bit ++)
        {
            char add = remain[max_len - bit - 1] - '0' + carry;
            sum[bit] = (add % 10) + '0';
            carry = add / 10;
        }
        sum[bit] = carry + '0';
    }
    if(sum[bit] == '0')
    {
        sum[bit] = '\0';
    }
    else
    {
        sum[bit + 1] = '\0';
    }
    int left = 0;
    int right = strlen(sum) - 1;
    while(left < right)
    {
        char tmp = sum[left];
        sum[left] = sum[right];
        sum[right] = tmp;
        left ++;
        right --;
    }
    return sum;
}
