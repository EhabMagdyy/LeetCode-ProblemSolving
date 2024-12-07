/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        unsigned short uniqueIdx = 0;
        unsigned short length = nums.size();
        for (unsigned short i = 1; i < length; ++i)
        {
            if (nums[uniqueIdx] != nums[i])
                nums[++uniqueIdx] = nums[i];
        }
        return uniqueIdx + 1;
    }
};
// @lc code=end
