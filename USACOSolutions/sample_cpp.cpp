/*
ID: kzz19941
TASK: test
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ofstream fout("test.out");
    std::ifstream fin("test.in");
    int a, b;
    fin >> a >> b;
    fout << (a + b) << "\n";
    return 0;
}
