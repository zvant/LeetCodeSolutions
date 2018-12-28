/*
ID: kzz19941
TASK: transform
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

typedef std::vector<std::vector<char>> Pattern;

void print(const Pattern & p)
{
    int N = p.size();
    for(int row = 0; row < N; row ++)
    {
        for(int col = 0; col < N; col ++)
        {
            std::cout << p[row][col];
        }
        std::cout << std::endl;
    }
}

Pattern reflect(int N, const Pattern & origin)
{
    Pattern tf = origin;
    for(int row = 0; row < N; row ++)
    {
        for(int col = 0; col < N / 2; col ++)
        {
            std::swap(tf[row][col], tf[row][N - 1 - col]);
        }
    }
    return tf;
}

Pattern rot90(int N, const Pattern & origin)
{
    Pattern tf = origin;
    for(int row = 0; row < N - 1; row ++)
    {
        for(int col = row + 1; col < N; col ++)
        {
            std::swap(tf[row][col], tf[col][row]);
        }
    }
    tf = reflect(N, tf);
    return tf;
}

int check(int N, const Pattern & origin, const Pattern & tf)
{
    if(rot90(N, origin) == tf)
    {
        return 1;
    }
    if(rot90(N, rot90(N, origin)) == tf)
    {
        return 2;
    }
    if(rot90(N, rot90(N, rot90(N, origin))) == tf)
    {
        return 3;
    }
    if(reflect(N, origin) == tf)
    {
        return 4;
    }
    if(rot90(N, reflect(N, origin)) == tf)
    {
        return 5;
    }
    if(rot90(N, rot90(N, reflect(N, origin))) == tf)
    {
        return 5;
    }
    if(rot90(N, rot90(N, rot90(N, reflect(N, origin)))) == tf)
    {
        return 5;
    }
    if(origin == tf)
    {
        return 6;
    }
    return 7;
}

int main()
{
    std::ofstream fout("transform.out");
    std::ifstream fin("transform.in");
    
    int N;
    fin >> N;
    Pattern origin, tf;
    std::string line;
    origin.resize(N);
    tf.resize(N);
    
    for(int idx = 0; idx < N; idx ++)
    {
        origin[idx].resize(N);
        fin >> line;
        for(int c = 0; c < N; c ++)
        {
            origin[idx][c] = line[c];
        }
    }
    for(int idx = 0; idx < N; idx ++)
    {
        tf[idx].resize(N);
        fin >> line;
        for(int c = 0; c < N; c ++)
        {
            tf[idx][c] = line[c];
        }
    }
    
    //print(origin);
    //std::cout << std::endl;
    //print(reflect(N, origin));
    
    fout << check(N, origin, tf) << std::endl;
    
    return 0;
}
