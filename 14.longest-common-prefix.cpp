/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string> &strs)
    {
        std::string lcp = "";
        bool isMismatched = false;
        unsigned char counter = 0;
        unsigned char vectIdxCntr = 0;
        unsigned char strIdxCntr = 0;
        unsigned char strsSize = strs.size();

        if (strsSize == 1)
            return strs.at(0);

        // Get min string length inside vector
        auto minString = std::min_element(strs.begin(), strs.end(),
                                          [](const std::string &a, const std::string &b)
                                          {
                                              return a.size() < b.size();
                                          });

        for (strIdxCntr = 0; strIdxCntr < minString->size(); ++strIdxCntr)
        {
            for (vectIdxCntr = 0; vectIdxCntr < strsSize - 1; ++vectIdxCntr)
            {
                if (strs.at(vectIdxCntr).at(strIdxCntr) != strs.at(vectIdxCntr + 1).at(strIdxCntr))
                {
                    isMismatched = true;
                    break;
                }
            }
            if (isMismatched)
                break;
            else
                lcp += strs.at(vectIdxCntr - 1).at(strIdxCntr);
        }

        return lcp;
    }
};
// @lc code=end
