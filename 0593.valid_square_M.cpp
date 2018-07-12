/**
 * https://leetcode.com/problems/valid-square/description/
 * 2017/06
 * 6 ms
 */

class Solution
{
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4)
    {
        int dist_sqs[6];
        // printf("%d - %d", INT_MIN, INT_MAX);
        dist_sqs[0] = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
        dist_sqs[1] = (p1[0] - p3[0]) * (p1[0] - p3[0]) + (p1[1] - p3[1]) * (p1[1] - p3[1]);
        dist_sqs[2] = (p1[0] - p4[0]) * (p1[0] - p4[0]) + (p1[1] - p4[1]) * (p1[1] - p4[1]);
        dist_sqs[3] = (p2[0] - p3[0]) * (p2[0] - p3[0]) + (p2[1] - p3[1]) * (p2[1] - p3[1]);
        dist_sqs[4] = (p2[0] - p4[0]) * (p2[0] - p4[0]) + (p2[1] - p4[1]) * (p2[1] - p4[1]);
        dist_sqs[5] = (p3[0] - p4[0]) * (p3[0] - p4[0]) + (p3[1] - p4[1]) * (p3[1] - p4[1]);
        sort(dist_sqs, dist_sqs + 6);
        return (dist_sqs[0] > 0 && dist_sqs[0] == dist_sqs[3] && dist_sqs[4] == dist_sqs[5]);
    }
};
