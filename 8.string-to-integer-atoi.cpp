/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution
{
public:
    int myAtoi(string s)
    {
        int num = 0;
        int validUntil = 0;
        bool numCaught = false;
        bool opCaught = false;
        bool isNegative = false;

        for (validUntil = 0; validUntil < s.size(); ++validUntil)
        {
            char ch = s.at(validUntil);
            if ('0' <= ch && ch <= '9')
                numCaught = true;
            else if ((ch == '-' || ch == '+') && !numCaught && !opCaught)
                opCaught = true;
            else if ((ch == '-' || ch == '+') && (numCaught || opCaught))
            {
                validUntil--;
                break;
            }
            else if (ch == ' ' && !numCaught && !opCaught)
            {
                continue;
            }
            else
            {
                validUntil--;
                break;
            }
        }

        if (validUntil == s.size())
            validUntil--;

        for (int i = 0; i <= validUntil; ++i)
        {
            char ch = s.at(i);
            if (ch != ' ')
            {
                if (ch == '-')
                    isNegative = true;
                else if ('0' <= ch && ch <= '9')
                {
                    int digit = ch - '0';
                    if (__builtin_mul_overflow(num, 10, &num) ||
                        __builtin_add_overflow(num, digit, &num))
                        return isNegative ? INT_MIN : INT_MAX;
                }
            }
        }
        return isNegative ? -num : num;
    }
};
// @lc code=end
