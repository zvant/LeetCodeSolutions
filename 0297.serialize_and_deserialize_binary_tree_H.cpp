/**
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 * 2015/11
 * 40 ms
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
private:
    struct SerialNode
    {
        int val;
        int l_idx;
        int r_idx;
        SerialNode(int e) : val(e), l_idx(-1), r_idx(-1) {}
    };
    int constructSerial(vector<SerialNode> & seq, TreeNode * root)
    {
        if(NULL == root)
            return -1;
        int idx = seq.size();
        SerialNode node(root -> val);
        seq.push_back(node);
        node.l_idx = constructSerial(seq, root -> left);
        node.r_idx = constructSerial(seq, root -> right);
        seq[idx] = node;
        return idx;
    }
    string encode(const vector<SerialNode> & seq)
    {
        char * buff = new char[sizeof(SerialNode) * seq.size()];
        for(int idx = 0; idx < seq.size(); idx ++)
        {
            SerialNode node = seq[idx];
            memcpy(buff + (sizeof(SerialNode) * idx), &node, sizeof(SerialNode));
        }
        string code(buff, sizeof(SerialNode) * seq.size());
        delete[] buff;
        return code;
    }
    TreeNode * restoreTree(const vector<SerialNode> & seq, int idx)
    {
        if(idx < 0 || seq.empty())
            return NULL;
        TreeNode * root = new TreeNode(seq[idx].val);
        root -> left = restoreTree(seq, seq[idx].l_idx);
        root -> right = restoreTree(seq, seq[idx].r_idx);
        return root;
    }
    void decode(vector<SerialNode> & seq, const string & code)
    {
        const char * buff = code.c_str();
        seq.clear();
        for(int idx = 0; idx < code.length() / sizeof(SerialNode); idx ++)
        {
            SerialNode node(0);
            memcpy(&node, buff + (sizeof(SerialNode) * idx), sizeof(SerialNode));
            seq.push_back(node);
        }
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode * root)
    {
        vector<SerialNode> seq;
        constructSerial(seq, root);
        return encode(seq);
    }
    // Decodes your encoded data to tree.
    TreeNode * deserialize(string data)
    {
        vector<SerialNode> seq;
        decode(seq, data);
        return restoreTree(seq, 0);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
