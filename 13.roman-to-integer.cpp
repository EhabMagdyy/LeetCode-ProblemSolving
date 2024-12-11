/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution
{
public:
    int romanToInt(string s)
    {
        std::unordered_map<char, unsigned short> values = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        unsigned short num = 0;
        unsigned short n = s.size();

        for (unsigned short i = 0; i < n; ++i)
        {
            // If the next character is larger, subtract the current character's value
            if ((i + 1 < n) && (values[s[i]] < values[s[i + 1]]))
            {
                num += (values[s[i + 1]] - values[s[i]]);
                ++i;
            }
            else
            {
                num += values[s[i]];
            }
        }

        return num;
    }
};
// @lc code=end
