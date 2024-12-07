/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int numsIdx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (val != nums[i])
                nums.at(numsIdx++) = nums[i];
        }
        return numsIdx;
    }
};
// @lc code=end

