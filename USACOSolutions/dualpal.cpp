/*
ID: kzz19941
TASK: dualpal
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
    std::ofstream fout("dualpal.out");
    std::ifstream fin("dualpal.in");
    
    int N, S;
    fin >> N >> S;
    
    char * buff = new char[100];
    
    while(N > 0)
    {
        S++;
        int count = 0;
        for(int base = 2; base <= 10; base ++)
        {
            if(count >= 2)
            {
                break;
            }
            int len = to_base(S, base, buff);
            bool is_pal = true;
            for(int pos = 0; pos < len / 2; pos ++)
            {
                if(buff[pos] != buff[len - 1 - pos])
                {
                    is_pal = false;
                    break;
                }
            }
            if(is_pal)
            {
                count ++;
            }
        }
        if(count >= 2)
        {
            N --;
            fout << S << std::endl;
        }
    }
    
    delete[] buff;
    
    return 0;
}
