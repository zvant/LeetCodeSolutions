/*
ID: kzz19941
TASK: crypt1
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <vector>
#include <utility>
#include <algorithm>

bool check_num(int n, int bits, const std::unordered_set<int> & digits)
{
    for(; bits > 0; bits --)
    {
        if(digits.count(n % 10) <= 0)
        {
            return false;
        }
        n /= 10;
    }
    return 0 == n;
}

bool check_prod(const int p1, const int p2, const std::unordered_set<int> & digits)
{
    return check_num(p1 * (p2 % 10), 3, digits) && \
           check_num(p1 * (p2 / 10), 3, digits) && \
           check_num(p1 * p2, 4, digits);
}

int main()
{
    std::ofstream fout("crypt1.out");
    std::ifstream fin("crypt1.in");
    
    int N;
    fin >> N;
    std::unordered_set<int> digits, results;
    std::vector<int> digits_list(N);
    for(int idx = 0; idx < N; idx ++)
    {
        fin >> digits_list[idx];
        digits.insert(digits_list[idx]);
    }
    
    for(int ia = 0; ia < N; ia ++)
    {
        for(int ib = 0; ib < N; ib ++)
        {
            for(int ic = 0; ic < N; ic ++)
            {
                for(int id = 0; id < N; id ++)
                {
                    for(int ie = 0; ie < N; ie ++)
                    {
                        int a = digits_list[ia];
                        int b = digits_list[ib];
                        int c = digits_list[ic];
                        int d = digits_list[id];
                        int e = digits_list[ie];
                        int p1 = 100 * a + 10 * b + c;
                        int p2 = 10 * d + e;
                        if(results.count(p1 * 100 + p2) < 1)
                        {
                            if(check_prod(p1, p2, digits))
                            {
                                results.insert(p1 * 100 + p2);
                            }
                        }
                    }
                }
            }
        }
    }
    fout << results.size() << std::endl;
    
    return 0;
}
