/*
ID: kzz19941
TASK: friday
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ofstream fout("friday.out");
    std::ifstream fin("friday.in");
    
    int d_m_leap[]{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int d_m_nleap[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int freqs[]{0, 0, 0, 0, 0, 0, 0};
    int curr_weekday = 1;
    
    int N;
    fin >> N;
    
    for(int idx = 0; idx < N; idx ++)
    {
        int year = 1900 + idx;
        int * d_m = NULL;
        if(((year % 100) == 0 && (year % 400) == 0) || \
            ((year % 100) != 0 && (year % 4) == 0))
        {
            d_m = d_m_leap;
        }
        else
        {
            d_m = d_m_nleap;
        }
        
        for(int idx = 0; idx < 12; idx ++)
        {
            int week_day = (curr_weekday + 13) % 7;
            freqs[week_day] += 1;
            curr_weekday += d_m[idx];
        }
    }
    
    for(int idx = 0; idx < 6; idx ++)
    {
        fout << freqs[idx] << " ";
    }
    fout << freqs[6] << std::endl;
    
    return 0;
}
