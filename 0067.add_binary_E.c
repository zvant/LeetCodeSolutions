/**
 * https://leetcode.com/problems/add-binary/description/
 * 2015/07
 * 0 ms
 */

char * addBinary(char * a, char * b)
{
    int len_a = strlen(a);
    int len_b = strlen(b);
    char * result;
    int len;
    if(len_a > len_b)
        len = len_a + 1;
    else
        len = len_b + 1;
    result = (char *)malloc((len + 1) * sizeof(char));
    memset(result, '0', len);
    result[len] = '\0';
    int ia = len_a - 1;
    int ib = len_b - 1;
    int i = len - 1;
    int flag = 0;
    int va, vb;
    while(i >= 0)
    {
        if(ia >= 0)
            va = a[ia] - '0';
        else
            va = 0;
        if(ib >= 0)
            vb = b[ib] - '0';
        else
            vb = 0;
        result[i] = '0' + (va + vb + flag) % 2;
        flag = (va + vb + flag) / 2;
        ia --;
        ib --;
        i --;
    }
    char * tmp = result;
    for(i = 0; i <= len - 2 && result[i] == '0'; i ++);
    result = (char *)malloc((len + 1 - i) * sizeof(char));
    strncpy(result, tmp + i, len + 1 - i);
    free(tmp);
    return result;
}
