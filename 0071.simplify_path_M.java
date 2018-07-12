/**
 * https://leetcode.com/problems/simplify-path/description/
 * 2015/07
 * 356 ms
 */

public class Solution
{
    public String simplifyPath(String path)
    {
        if(path.length() <= 0)
            return new String();
        String dirs[] = path.split("/");
        if(dirs.length <= 0)
            return "/";
        Stack<String> segs = new Stack<String>();
        for(String dir : dirs)
        {
            if(dir.equals("."))
                continue;
            if(dir.equals(".."))
            {
                if(! segs.empty())
                    segs.pop();
                continue;
            }
            if(dir.length() > 0)
                segs.push(dir);
        }
        if((! segs.empty()) && segs.peek().length() <= 0)
            segs.pop();
        String result = new String();
        while(! segs.empty())
            result = "/" + segs.pop() + result;
        
        if(result.length() <= 0 && path.startsWith("/"))
            result = "/" + result;
        return result;
    }
}
