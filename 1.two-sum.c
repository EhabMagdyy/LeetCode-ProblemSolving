/*
 * @lc app=leetcode id=1 lang=c
 *
 * [1] Two Sum
 */

// @lc code=start
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    static int indices[2];
    *returnSize = 2;
    for (int i = 0; i < numsSize - 1; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                indices[0] = i;
                indices[1] = j;
                break;
            }
        }
    }
    return indices;
}
// @lc code=end
