/**
 * https://leetcode.com/problems/validate-ip-address/description/
 * 2017/01
 * 3 ms
 */

class Solution
{
private:
    int len;
    string ipv4_str = string("IPv4");
    string ipv6_str = string("IPv6");
    string none_str = string("Neither");
    bool inCharset(const char & c)
    {
        return ('.' == c) || (':' == c) || isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
    }
    int digitToNum(const char & c)
    {// assume to be in "0123456789abcdef"
        if(isdigit(c))
        {
            return c - '0';
        }
        else
        {
            return c - 'a' + 10;
        }
    }
    
    bool checkIPv4Segment(const char * ip, int begin, int end)
    {
        if(end - begin < 1 || end - begin > 3 || (ip[begin] == '0' && end - begin > 1))
        {
            return false;
        }
        int num = 0;
        for(int idx = begin; idx < end; idx ++)
        {
            if(! isdigit(ip[idx]))
            {
                return false;
            }
            num = num * 10 + digitToNum(ip[idx]);
        }
        return num < 256;
    }
    bool checkIPv4(const char * ip)
    {
        int count = 0;
        int begin = 0;
        while(begin < len)
        {
            int end = begin;
            while(ip[end] != '.' && end < len) end ++;
            count ++;
            if(! checkIPv4Segment(ip, begin, end))
            {
                return false;
            }
            begin = end + 1;
        }
        return 4 == count && begin == len + 1;
    }
    
    bool checkIPv6Segment(const char * ip, int begin, int end)
    {
        if(end - begin > 4 || end - begin < 1)
        {
            return false;
        }
        int num = 0;
        for(int idx = begin; idx < end; idx ++)
        {
            num = num * 10 + digitToNum(ip[idx]);
        }
        return num < 65536;
    }
    bool checkIPv6(const char * ip)
    {
        int count = 0;
        int begin = 0;
        while(begin < len)
        {
            int end = begin;
            while(ip[end] != ':' && end < len) end ++;
            count ++;
            if(! checkIPv6Segment(ip, begin, end))
            {
                return false;
            }
            begin = end + 1;
        }
        return 8 == count && begin == len + 1;
    }
    
public:
    string validIPAddress(string IP)
    {
        len = IP.length();
        char * ip_str = new char[len];
        bool is_ipv4 = false;
        bool is_ipv6 = false;
        for(int idx = 0; idx < len; idx ++)
        {
            char c = IP[idx];
            if(! inCharset(c))
            {
                is_ipv4 = is_ipv6 = false;
                break;
            }
            if('.' == c)
            {
                is_ipv4 = true;
            }
            if(':' == c)
            {
                is_ipv6 = true;
            }
            ip_str[idx] = tolower(c);
        }
        if(is_ipv4 && ! is_ipv6)
        {
            bool result = checkIPv4(ip_str);
            delete ip_str;
            return result ? ipv4_str : none_str;
        }
        if(is_ipv6 && ! is_ipv4)
        {
            bool result = checkIPv6(ip_str);
            delete ip_str;
            return result ? ipv6_str : none_str;
        }
        delete ip_str;
        return none_str;
    }
};
