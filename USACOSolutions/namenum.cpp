/*
ID: kzz19941
TASK: namenum
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

void check_names( \
    const std::vector<std::vector<char>> & pad, \
    const std::unordered_set<std::string> & dict, \
    const std::string digits, \
    int pos, \
    char * buff, \
    std::vector<std::string> & valid_names)
{
    if(pos == digits.length())
    {
        buff[pos] = '\0';
        std::string n(buff);
        //std::cout << n << "|";
        if(dict.count(n) > 0)
        {
            valid_names.push_back(n);
        }
        return;
    }
    
    for(int idx = 0; idx < 3; idx ++)
    {
        buff[pos] = pad[digits[pos] - '0'][idx];
        check_names(pad, dict, digits, pos + 1, buff, valid_names);
    }
}

int main()
{
    std::ofstream fout("namenum.out");
    std::ifstream fin("namenum.in");
    std::ifstream dictin("dict.txt");
    
    std::vector<std::vector<char>> pad;
    pad.resize(10);
    pad[2] = std::vector<char>({'A', 'B', 'C'});
    pad[3] = std::vector<char>({'D', 'E', 'F'});
    pad[4] = std::vector<char>({'G', 'H', 'I'});
    pad[5] = std::vector<char>({'J', 'K', 'L'});
    pad[6] = std::vector<char>({'M', 'N', 'O'});
    pad[7] = std::vector<char>({'P', 'R', 'S'});
    pad[8] = std::vector<char>({'T', 'U', 'V'});
    pad[9] = std::vector<char>({'W', 'X', 'Y'});
    
    std::unordered_set<std::string> names;
    std::string name;
    while(dictin >> name)
    {
        names.insert(name);
    }
    
    std::string digits;
    fin >> digits;
    char * buff = (char *)malloc(sizeof(char) * 20);
    std::vector<std::string> valid_names;
    check_names(pad, names, digits, 0, buff, valid_names);
    
    for(int idx = 0; idx < valid_names.size(); idx ++)
    {
        fout << valid_names[idx] << std::endl;
    }
    if(valid_names.empty())
    {
        fout << "NONE\n";
    }
    
    return 0;
}
