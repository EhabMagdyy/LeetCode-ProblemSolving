/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        unsigned short nums1Size = nums1.size();
        unsigned short nums2Size = nums2.size();
        unsigned short mergedSize = nums1Size + nums2Size;
        unsigned short nums1Counter = 0;
        unsigned short nums2Counter = 0;
        unsigned short mergedCounter = 0;
        int last = 0, now = 0;
        double result = 0;

        while (mergedCounter <= mergedSize / 2 && nums1Counter < nums1Size && nums2Counter < nums2Size)
        {
            last = now;
            (nums1.at(nums1Counter) < nums2.at(nums2Counter)) ? now = nums1.at(nums1Counter++) : now = nums2.at(nums2Counter++);
            mergedCounter++;
        }
        while (mergedCounter <= mergedSize / 2 && nums1Counter < nums1Size)
        {
            last = now;
            now = nums1.at(nums1Counter++);
            mergedCounter++;
        }
        while (mergedCounter <= mergedSize / 2 && nums2Counter < nums2Size)
        {
            last = now;
            now = nums2.at(nums2Counter++);
            mergedCounter++;
        }
        if (mergedSize % 2)
            return static_cast<double>(now);
        return (static_cast<double>(now) + static_cast<double>(last)) / 2;
    }
};
// @lc code=end
