/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        std::unordered_map<char, int> lastSeen;
        int longest = 0;
        int start = 0; // Start of the sliding window

        for (int end = 0; end < s.size(); ++end)
        {
            char c = s[end];

            // If character in the map, move the start pointer
            if (lastSeen.find(c) != lastSeen.end() && lastSeen[c] >= start)
            {
                start = lastSeen[c] + 1;
            }

            lastSeen[c] = end;

            longest = std::max(longest, end - start + 1);
        }

        return longest;
    }
};
// @lc code=end
