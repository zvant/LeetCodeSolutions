/**
 * https://leetcode.com/problems/construct-the-rectangle/description/
 * 2017/02
 * 83 ms
 */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * constructRectangle(int area, int * returnSize)
{
    * returnSize = 2;
    int * rect = (int *)malloc(2 * sizeof(int));
    if(area < 4)
    {
        rect[0] = area;
        rect[1] = 1;
        return rect;
    }
    int l = sqrt(area);
    while(area % l != 0)
    {
        l ++;
    }
    rect[0] = l;
    rect[1] = area / l;
    if(rect[1] > rect[0])
    {
        l = rect[1];
        rect[1] = rect[0];
        rect[0] = l;
    }
    return rect;
}
