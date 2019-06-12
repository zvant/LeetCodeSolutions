/**
 * https://leetcode.com/problems/map-sum-pairs/
 * 2019/06
 * 4 ms
 */

class MapSum
{
    struct TrieNode
    {
        int val;
        bool leaf;
        TrieNode * nexts[26];
        TrieNode()
        {
            leaf = false;
            std::fill(nexts, nexts + 26, (TrieNode *)NULL);
        }
    };
    TrieNode * trie_root = NULL;
    
    int trie_sum(TrieNode * root)
    {
        if(NULL == root)
        {
            return 0;
        }
        int summary = 0;
        if(root -> leaf)
        {
            summary += root -> val;
        }
        for(int idx = 0; idx < 26; idx ++)
        {
            summary += trie_sum(root -> nexts[idx]);
        }
        return summary;
    }

public:
    /** Initialize your data structure here. */
    MapSum()
    {
        trie_root = new TrieNode;
    }
    
    void insert(string key, int val)
    {
        TrieNode * ptr = trie_root;
        for(int idx = 0; idx < key.length(); idx ++)
        {
            int shift = key[idx] - 'a';
            if(ptr -> nexts[shift] == NULL)
            {
                ptr -> nexts[shift] = new TrieNode;
            }
            ptr = ptr -> nexts[shift];
        }
        ptr -> leaf = true;
        ptr -> val = val;
    }
    
    int sum(string prefix)
    {
        TrieNode * ptr = trie_root;
        for(int idx = 0; idx < prefix.length(); idx ++)
        {
            ptr = ptr -> nexts[prefix[idx] - 'a'];
            if(NULL == ptr)
            {
                return 0;
            }
        }
        return trie_sum(ptr);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
