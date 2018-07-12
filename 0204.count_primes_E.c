/**
 * https://leetcode.com/problems/count-primes/description/
 * 2015/07
 * 76 ms
 */

int countPrimes(int n)
{
    n --;
    if(n <= 1)
        return 0;
    
    char * is_prime = (char *)malloc(n + 1);
    memset(is_prime, 1, n + 1);
    is_prime[0] = is_prime[1] = 0;
    
    int prime, multi;
    for(prime = 2; prime < n / 2 + 1; prime ++)
    {
        if(is_prime[prime] == 0)
            continue;
        
        for(multi = 2; multi * prime <= n; multi ++)
        {
            is_prime[multi * prime] = 0;
        }
    }
    
    int count = 0;
    int idx;
    for(idx = 0; idx <= n; idx ++)
        count += is_prime[idx];
    free(is_prime);
    return count;
}
