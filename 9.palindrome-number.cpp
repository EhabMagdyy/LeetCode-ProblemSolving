/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        unsigned int n = x;
        unsigned int inv = 0;
        while (n)
        {
            inv *= 10;
            inv += n % 10;
            n /= 10;
        }
        return inv == x;
    }
};
// @lc code=end
