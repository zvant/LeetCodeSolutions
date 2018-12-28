/*
ID: kzz19941
TASK: palsquare
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

char base_digit(int k, int base)
{
    if(k < 0 || k > 30)
    {
        return '!';
    }
    if(k < 10)
    {
        return '0' + char(k);
    }
    return 'A' + char(k - 10);
}

int to_base(int n, int base, char * buff)
{
    int idx = 0;
    while(n > 0)
    {
        buff[idx] = base_digit(n % base, base);
        n /= base;
        idx ++;
    }
    buff[idx] = '\0';
    for(int shift = 0; shift < idx / 2; shift ++)
    {
        std::swap(buff[shift], buff[idx - 1 - shift]);
    }
    return idx;
}

int main()
{
    std::ofstream fout("palsquare.out");
    std::ifstream fin("palsquare.in");
    
    int base;
    char * buff = new char[20];
    fin >> base;
    
    for(int n = 1; n <= 300; n ++)
    {
        int square = n * n;
        int len = to_base(square, base, buff);
        bool is_pal = true;
        for(int idx = 0; idx < len / 2; idx ++)
        {
            if(buff[idx] != buff[len - 1 - idx])
            {
                is_pal = false;
                break;
            }
        }
        if(is_pal)
        {
            std::string square_str(buff);
            to_base(n, base, buff);
            fout << std::string(buff) << " " << square_str << std::endl;
        }
    }
    
    return 0;
}
