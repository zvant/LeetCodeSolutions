/**
 * https://leetcode.com/problems/add-and-search-word-data-structure-design/description/
 * 2015/08
 * 124 ms
 */

class DictionaryNode
{
private:
    static const int CHILD_SIZE = 'z' - 'a' + 1;
    char ch;
    DictionaryNode ** children;
    int count;
    
public:
    DictionaryNode(char c)
    {
        ch = c;
        children = new DictionaryNode * [CHILD_SIZE]();
        count = 0;
    }
    DictionaryNode() : ch('\0'), children(NULL), count(0) {}
    ~DictionaryNode() { delete[] children; }
    
    void recordOne() { count ++; }
    bool hasRecord() const { return (count > 0); }
    DictionaryNode * & operator[](char c) const { return children[(c - 'a') % 26]; }
};

class WordDictionary
{
private:
    DictionaryNode * dict;
    
    bool searchFrom(DictionaryNode * node, string word) const
    {
        int len = word.length();
        if(NULL == node)
            return false;
        
        DictionaryNode * ptr = node;
        for(int idx = 0; idx < len; idx ++)
        {
            char c = word[idx];
            if((! isalpha(c)) && ('.' != c))
                return false;
            
            if('.' == c)
            {
                word.erase(0, idx + 1);
                for(c = 'a'; c <= 'z'; c ++)
                {
                    if(searchFrom((* ptr)[c], word))
                        return true;
                }
                return false;
            }
            else
            {
                ptr = (* ptr)[c];
                if(NULL == ptr)
                    return false;
            }
        }
        return ptr -> hasRecord();
    }
    
public:
    WordDictionary()
    {
        dict = new DictionaryNode('\0');
    }
    void addWord(string word)
    {
        int len = word.length();
        if(len <= 0)
            return;
        for(int i = 0; i < len; i ++)
            if(! isalpha(word[i]))
                return;
        
        DictionaryNode * ptr = dict;
        for(int idx = 0; idx < len; idx ++)
        {
            char c = word[idx];
            if(NULL == (* ptr)[c])
            {
                (* ptr)[c] = new DictionaryNode(c);
            }
            ptr = (* ptr)[c];
        }
        ptr -> recordOne();
    }

    bool search(string word) const
    {
        if(word.length() <= 0)
            return true;
        return searchFrom(dict, word);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
