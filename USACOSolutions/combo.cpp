/*
ID: kzz19941
TASK: combo
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <utility>
#include <unordered_set>
#include <string>

void check(int c1, int c2, int c3, int N, std::unordered_set<std::string> & checked)
{
    char * buff = new char[100];
    for(int s1 = -2; s1 <= 2; s1 ++)
    {
        for(int s2 = -2; s2 <= 2; s2 ++)
        {
            for(int s3 = -2; s3 <= 2; s3 ++)
            {
                snprintf(buff, 90, "%d|%d|%d", (c1 + s1 + N) % N, (c2 + s2 + N) % N, (c3 + s3 + N) % N);
                std::string str(buff);
                //std::cout << str << std::endl;
                if(checked.count(str) < 1)
                {
                    checked.insert(str);
                }
            }
        }
    }
    delete[] buff;
}

int main()
{
    std::ofstream fout("combo.out");
    std::ifstream fin("combo.in");
    
    int N, c1, c2, c3, m1, m2, m3;
    fin >> N >> c1 >> c2 >> c3 >> m1 >> m2 >> m3;
    
    std::unordered_set<std::string> checked;
    check(c1, c2, c3, N, checked);
    check(m1, m2, m3, N, checked);
    fout << checked.size() << std::endl;
    
    return 0;
}
