/**
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 * 2015/07
 * 568 ms
 */

public class Solution
{
    public String reverseWords(String s)
    {
        String words[] = s.split(" ");
        String result = new String();
        if(words.length <= 0)
            return result;
        for(int i = words.length - 1; i > 0; i --)
        {
            result = result + words[i];
            if(words[i - 1].length() > 0)
                result += " ";
        }
        result = result + words[0];
        return result;
    }
}
