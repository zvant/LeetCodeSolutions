/**
 * https://leetcode.com/problems/first-bad-version/description/
 * 2015/09
 * 0 ms
 */

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int findFirstBad(int begin, int end) // both inclusive
{
    if(begin > end || (! isBadVersion(end)))
        return -1;
    
    if(end - begin < 10)
    {
        int idx = begin;
        while(idx < end && (! isBadVersion(idx)))
            idx ++;
        return idx;
    }
    
    int mid = begin + (end - begin) / 2;
    if(isBadVersion(mid))
        return findFirstBad(begin, mid);
    else
        return findFirstBad(mid + 1, end);
}

int firstBadVersion(int n)
{
    if(n <= 0)
        return -1;
    
    return findFirstBad(1, n);
}
