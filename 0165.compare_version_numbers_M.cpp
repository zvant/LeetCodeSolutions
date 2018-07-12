/**
 * https://leetcode.com/problems/compare-version-numbers/description/
 * 2015/07
 * 0 ms
 */

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        size_t idx1, idx2;
        int v1 = std::stoi(version1, &idx1, 10);
        int v2 = std::stoi(version2, &idx2, 10);
        if(v1 < v2)
            return -1;
        if(v1 > v2)
            return 1;
        // v1 == v2
        if(idx1 == version1.length() && idx2 == version2.length())
            return 0;
        if(idx1 == version1.length())
            idx1 --;
        if(idx2 == version2.length())
            idx2 --;
        
        const char * str1 = version1.c_str() + idx1 + 1;
        const char * str2 = version2.c_str() + idx2 + 1;
        
        return compareVersion(string((* str1 == '\0' ? "0" : str1)), string((* str2 == '\0' ? "0" : str2)));
    }
};
