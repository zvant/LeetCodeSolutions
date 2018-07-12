/**
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 * 2015/08
 * 60 ms
 */

class TrieNode
{
private:
    static const int CHILD_SIZE = 'z' - 'a' + 1;
    char ch;
    TrieNode ** children;
    int count;
    
public:
    TrieNode(char c)
    {
        ch = c;
        children = new TrieNode * [CHILD_SIZE]();
        count = 0;
    }
    TrieNode() : ch('\0'), children(NULL), count(0) {}
    ~TrieNode() { delete[] children; }
    
    void recordOne()
    {
        count ++;
    }
    bool hasRecord() const
    {
        return (count > 0);
    }
    TrieNode * & operator[](char c) const
    {
        return children[(c - 'a') % 26];
    }
};

class Trie
{
private:
    TrieNode * root;
public:
    Trie()
    {
        root = new TrieNode('\0');
    }
    
    void insert(string word)
    {
        int len = word.length();
        if(len <= 0)
            return;
        for(int i = 0; i < len; i ++)
            if(! isalpha(word[i]))
                return;
        
        TrieNode * ptr = root;
        for(int idx = 0; idx < len; idx ++)
        {
            char c = word[idx];
            if(NULL == (* ptr)[c])
            {
                (* ptr)[c] = new TrieNode(c);
            }
            ptr = (* ptr)[c];
        }
        ptr -> recordOne();
    }

    bool search(string word)
    {
        int len = word.length();
        if(len <= 0)
            return true;
        
        TrieNode * ptr = root;
        for(int idx = 0; idx < len; idx ++)
        {
            char c = word[idx];
            if(! isalpha(c))
                return false;
            ptr = (* ptr)[c];
            if(NULL == ptr)
                return false;
        }
        return ptr -> hasRecord();
    }
    
    bool startsWith(string prefix)
    {
        int len = prefix.length();
        if(len <= 0)
            return true;
        
        TrieNode * ptr = root;
        for(int idx = 0; idx < len; idx ++)
        {
            char c = prefix[idx];
            if(! isalpha(c))
                return false;
            ptr = (* ptr)[c];
            if(NULL == ptr)
                return false;
        }
        return true;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
