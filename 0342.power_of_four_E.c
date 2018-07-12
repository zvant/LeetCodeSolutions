/**
 * https://leetcode.com/problems/power-of-four/description/
 * 2016/05
 * 8 ms
 */

bool isPowerOfFour(int num) {
    if(num <= 0)
        return false;
    
    int logee = (int)(log(num) / log(4));
    return num == (int)pow(4, logee);
}
