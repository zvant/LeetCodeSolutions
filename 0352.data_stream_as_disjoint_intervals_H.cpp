/**
 * https://leetcode.com/problems/data-stream-as-disjoint-intervals/
 * 2018/12
 * 136 ms
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool comp_Interval(const Interval & i1, const Interval & i2)
{
    return i1.start < i2.start;
}

struct IntervalNode
{
    int start, end;
    IntervalNode * left, * right;
    IntervalNode() : start(-1), end(-1), left(NULL), right(NULL) {}
};

class SummaryRanges
{
private:
    IntervalNode * bst = NULL;
    
    void inOrderTraverse(IntervalNode * root, vector<Interval> & intervals)
    {
        if(NULL != root)
        {
            inOrderTraverse(root -> left, intervals);
            Interval i(root -> start, root -> end);
            intervals.push_back(i);
            inOrderTraverse(root -> right, intervals);
        }
    }
    
    void addNodeVal(IntervalNode * root, int val)
    {
        if(0 > (root -> start))
        {
            root -> start = val;
            root -> end = val;
            return;
        }
        
        if(val >= (root -> start - 1) && val <= (root -> end + 1))
        {
            root -> start = min(root -> start, val);
            root -> end = max(root -> end, val);
        }
        else
        {
            if(val < (root -> start - 1))
            {
                if(NULL == root -> left)
                {
                    root -> left = new IntervalNode();
                }
                addNodeVal(root -> left, val);
            }
            else
            {
                if(NULL == root -> right)
                {
                    root -> right = new IntervalNode();
                }
                addNodeVal(root -> right, val);
            }
        }
        
        if(NULL != root -> left && (root -> left -> end) >= (root -> start - 1))
        {
            root -> start = root -> left -> start;
            IntervalNode * left = root -> left -> left;
            delete root -> left;
            root -> left = left;
        }
        
        if(NULL != root -> right && (root -> right -> start) <= (root -> end + 1))
        {
            root -> end = root -> right -> end;
            IntervalNode * right = root -> right -> right;
            delete root -> right;
            root -> right = right;
        }
    }

public:
    /** Initialize your data structure here. */
    SummaryRanges()
    {
        bst = new IntervalNode();
    }
    
    void addNum(int val)
    {
        addNodeVal(bst, val);
    }
    
    vector<Interval> getIntervals()
    {
        vector<Interval> intervals;
        if(bst -> start < 0)
        {
            return intervals;
        }
        
        if(bst -> start >= 0)
        {
            inOrderTraverse(bst, intervals);
        }
        sort(intervals.begin(), intervals.end(), comp_Interval);
        vector<Interval> results;
        results.push_back(intervals[0]);
        
        for(int idx = 1; idx < intervals.size(); idx ++)
        {
            Interval & i = intervals[idx];
            Interval & i_last = results[results.size() - 1];
            
            if(i.start <= i_last.end + 1)
            {
                i_last.end = max(i.end, i_last.end);
            }
            else
            {
                results.push_back(i);
            }
        }
        return results;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<Interval> param_2 = obj->getIntervals();
 */