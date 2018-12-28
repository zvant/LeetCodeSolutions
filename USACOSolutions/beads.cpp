/*
ID: kzz19941
TASK: beads
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <utility>

int main()
{
    std::ofstream fout("beads.out");
    std::ifstream fin("beads.in");
    
    int N;
    std::string lace;
    fin >> N >> lace;
    
    char curr_c = '\0';
    
    for(int idx = 0; idx < lace.length(); idx ++)
    {
        if(lace[idx] != 'w')
        {
            curr_c = lace[idx];
            break;
        }
    }
    if(curr_c == '\0')
    {
        fout << N << std::endl;
        return 0;
    }
    
    int max_len = 0;
    lace = lace + lace;
    
    int idx = 0;
    while(idx < lace.length())
    {
        while(idx < lace.length() && (lace[idx] =='w' || lace[idx] == curr_c))
        {
            idx ++;
        }
        char next_c = 'r';
        if(curr_c == 'r')
        {
            next_c = 'b';
        }
        int l_shift, r_shift;
        for(l_shift = 1; \
            (idx - l_shift) >= 0 && \
            (lace[idx - l_shift] == 'w' || lace[idx - l_shift] == curr_c);
            l_shift ++);
        for(r_shift = 0; r_shift < N && \
            (lace[idx + r_shift] == 'w' || lace[idx + r_shift] == next_c);
            r_shift ++);
        int len = l_shift + r_shift - 1;
        max_len = std::max(len, max_len);
        curr_c = next_c;
    }
    if(max_len > N)
    {
        max_len = N;
    }
    fout << max_len << std::endl;
    
    return 0;
}
