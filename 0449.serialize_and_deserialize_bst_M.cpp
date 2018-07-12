/**
 * https://leetcode.com/problems/serialize-and-deserialize-bst/description/
 * 2017/01
 * 26 ms
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
    const static int NULL_IDX = -1;
    int countNodes(TreeNode * root)
    {
        if(NULL == root)
        {
            return 0;
        }
        else
        {
            return 1 + countNodes(root -> left) + countNodes(root -> right);
        }
    }
    void flattenTree(int * buff, TreeNode * root, int & idx)
    {
        // assert(NULL != root);
        int pos = idx * 3;
        buff[pos] = root -> val;
        if(NULL != root -> left)
        {
            idx ++;
            buff[pos + 1] = idx;
            flattenTree(buff, root -> left, idx);
        }
        else
        {
            buff[pos + 1] = NULL_IDX;
        }
        if(NULL != root -> right)
        {
            idx ++;
            buff[pos + 2] = idx;
            flattenTree(buff, root -> right, idx);
        }
        else
        {
            buff[pos + 2] = NULL_IDX;
        }
    }
    TreeNode * constructTree(int * buff, int idx)
    {
        int pos = idx * 3;
        TreeNode * root = new TreeNode(buff[pos]);
        int left_idx = buff[pos + 1];
        int right_idx = buff[pos + 2];
        if(NULL_IDX != left_idx)
        {
            root -> left = constructTree(buff, left_idx);
        }
        if(NULL_IDX != right_idx)
        {
            root -> right = constructTree(buff, right_idx);
        }
        return root;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode * root)
    {
        if(NULL == root)
        {
            return string("");
        }
        int count = countNodes(root);
        int * buff = new int[count * 3];
        int start = 0;
        flattenTree(buff, root, start);
        string encoded((char *)buff, sizeof(int) * count * 3);
        delete[] buff;
        return encoded;
    }

    // Decodes your encoded data to tree.
    TreeNode * deserialize(string data)
    {
        int count = data.length() / 3;
        if(count < 1)
        {
            return NULL;
        }
        int * buff = (int *)(data.c_str());
        return constructTree(buff, 0);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
