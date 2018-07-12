/**
 * https://leetcode.com/problems/isomorphic-strings/description/
 * 2015/07
 * 0 ms
 */

#define MAP_SIZE 256

bool isIsomorphic(char * s, char * t)
{
    if(strlen(s) != strlen(t))
        return false;
    int len = strlen(s);
    
    char * mapping_s2t = (char *)malloc(MAP_SIZE);
    memset(mapping_s2t, '\0', MAP_SIZE);
    char * mapping_t2s = (char *)malloc(MAP_SIZE);
    memset(mapping_t2s, '\0', MAP_SIZE);
    
    int idx;
    for(idx = 0; idx < len; idx ++)
    {
        if(mapping_s2t[s[idx]] == '\0')
        {
            mapping_s2t[s[idx]] = t[idx];
        }
        else if(mapping_s2t[s[idx]] != t[idx])
        {
            return false;
        }
        
        if(mapping_t2s[t[idx]] == '\0')
        {
            mapping_t2s[t[idx]] = s[idx];
        }
        else if(mapping_t2s[t[idx]] != s[idx])
        {
            return false;
        }
    }
    return true;
}
