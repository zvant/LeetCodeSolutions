/**
 * https://leetcode.com/problems/kth-largest-element-in-a-stream/
 * 2019/06
 * 56 ms
 */

bool comp(const int & x1, const int & x2)
{
    return x1 >= x2;
}

class KthLargest
{
    int K_;
    vector<int> heap;
public:
    KthLargest(int k, vector<int>& nums)
    {
        K_ = k;
        heap = nums;
        heap.push_back(INT_MIN); heap.push_back(INT_MIN);
        std::make_heap(heap.begin(), heap.end(), comp);
        for(int idx = 0; idx < heap.size() - k; idx ++)
        {
            std::pop_heap(heap.begin(), heap.end() - idx, comp);
        }
        // for(int idx = 0; idx < heap.size(); idx ++)
        // {
        //     printf("%d,", heap[idx]);
        // }
        // printf("\n");
    }
    
    int add(int val)
    {
        heap[K_] = val;
        std::push_heap(heap.begin(), heap.begin() + K_ + 1, comp);
        std::pop_heap(heap.begin(), heap.begin() + K_ + 1, comp);
        return heap[0];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */