/**
 * https://leetcode.com/problems/course-schedule/description/
 * 2015/08
 * 268 ms
 */

struct PostNode
{
    int val;
    PostNode * next;
    PostNode() : val(-1), next(NULL) {}
};

struct Node
{
    int val;
    int in_num;
    PostNode * post;
    PostNode * last;
    Node() : val(-1), in_num(0)
    {
        post = new PostNode;
        last = post;
    }
};

class Solution
{
private:
    vector<Node> nodes;
    int num;
    int num_node;
public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites)
    {
        num = numCourses;
        num_node = num;
        if(num <= 0 || prerequisites.size() <= 0)
            return true;
        
        nodes.clear();
        for(int i = 0; i < numCourses; i ++)
        {
            Node n;
            n.val = i;
            nodes.push_back(n);
        }
        
        for(int i = 0; i < prerequisites.size(); i ++)
        {
            pair<int, int> edge = prerequisites[i];
            PostNode * p = nodes[edge.second].last;
            p -> next = new PostNode;
            p = p -> next;
            p -> val = edge.first;
            nodes[edge.second].last = p;
            nodes[edge.first].in_num ++;
        }
        
        while(true)
        {
            if(num_node <= 0)
                return true;
            
            int idx;
            for(idx = 0; idx < num; idx ++)
            {
                if(nodes[idx].val < 0)
                    continue;
                if(nodes[idx].in_num <= 0)
                    break;
            }
            if(idx >= num)
            {
                for(int i = 0; i < num; i ++)
                    if(nodes[i].val > 0)
                        return false;
                return true;
            }
            
            num_node --;
            nodes[idx].val = -1;
            PostNode * p = (nodes[idx].post) -> next;
            (nodes[idx].post) -> next = NULL;
            nodes[idx].last = nodes[idx].post;
            while(p != NULL)
            {
                nodes[p -> val].in_num --;
                PostNode * tmp = p;
                p = p -> next;
                delete tmp;
            }
        }
    }
};
