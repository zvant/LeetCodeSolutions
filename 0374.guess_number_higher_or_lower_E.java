/**
 * https://leetcode.com/problems/guess-number-higher-or-lower/description/
 * 2016/07
 * 1 ms
 */

/* The guess API is defined in the parent class GuessGame.
   @param num, your guess
   @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
      int guess(int num); */

public class Solution extends GuessGame
{
    public int guessNumber(int n)
    {
        int low = 1;
        int high = n;
        while(high - low > 1)
        {
            int mid = (int)(((double)low + high) / 2);
            if(guess(mid) == 0)
                return mid;
            
            if(guess(mid) < 0)
                high = mid - 1;
            else
                low = mid + 1;
        }
        if(guess(low) == 0)
            return low;
        return high;
    }
}
