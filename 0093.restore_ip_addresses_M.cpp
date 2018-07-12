/**
 * https://leetcode.com/problems/restore-ip-addresses/description/
 * 2015/07
 * 4 ms
 */

class Solution
{
private:
    string addr;
    vector<string> results;
    int len;
    void segAddr(string ip, int idx, int segs)
    {
        if(segs == 0)
        {
            if(idx == len)
                results.push_back(ip);
            return;
        }
        if(idx >= len)
            return;
        if(idx < len && isdigit(addr[idx]))
        {
            string new_ip = ip;
            new_ip += addr[idx];
            new_ip += '.';
            segAddr(new_ip, idx + 1, segs - 1);
        }
        if(idx + 1 < len && isdigit(addr[idx + 1]))
        {
            if(addr[idx] == '0')
                return;
            string new_ip = ip;
            new_ip += addr[idx];
            new_ip += addr[idx + 1];
            new_ip += '.';
            segAddr(new_ip, idx + 2, segs - 1);
        }
        if(idx + 2 < len && isdigit(addr[idx + 2]))
        {
            if(addr[idx] == '0')
                return;
            if((addr[idx] - '0') * 100 + (addr[idx + 1] - '0') * 10 + addr[idx + 2] - '0' > 255)
                return;
            string new_ip = ip;
            new_ip += addr[idx];
            new_ip += addr[idx + 1];
            new_ip += addr[idx + 2];
            new_ip += '.';
            segAddr(new_ip, idx + 3, segs - 1);
        }
    }
public:
    vector<string> restoreIpAddresses(string s)
    {
        addr = s;
        len = addr.length();
        string ip;
        results.clear();
        segAddr(ip, 0, 4);
        for(int i = 0; i < results.size(); i ++)
            results[i].erase(results[i].length() - 1, 1);
        return results;
    }
};
