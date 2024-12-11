/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        int result = 0;
        bool isNegative = false;
        if (0 > x)
        {
            if (__builtin_mul_overflow(x, -1, &x))
                return 0;
            isNegative = true;
        }
        while (x)
        {
            if (__builtin_mul_overflow(result, 10, &result))
                return 0;
            if (__builtin_add_overflow(result, x % 10, &result))
                return 0;
            x /= 10;
        }
        if (isNegative)
            result *= -1;

        return result;
    }
};
// @lc code=end
