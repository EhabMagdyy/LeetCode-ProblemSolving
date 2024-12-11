/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution
{
public:
    bool isValid(std::string s)
    {
        // if size is odd -> not valid
        if (s.size() % 2)
            return false;

        bool isValid = true;
        std::stack<std::string> prnths;
        std::string left = "({[";
        std::string right = ")}]";

        unsigned short length = s.size();

        for (unsigned short i = 0; i < length; ++i)
        {
            char l = s.at(i);
            // left -> ( , { , [
            if (left.find(l) != s.npos)
                prnths.push(s.substr(i, 1));
            // right -> ) , } , ]
            else
            {
                // empty -> false          - top is right -> false
                if (true == prnths.empty() || right.find(prnths.top()) != s.npos)
                {
                    isValid = false;
                    break;
                }
                // top is left
                else
                {
                    // check if top(left) doesn't matche right parenthenses
                    if (left.find(prnths.top()) != right.find(l))
                    {
                        isValid = false;
                        break;
                    }
                    else
                        prnths.pop();
                }
            }
        }
        if (true != prnths.empty())
            return false;

        return isValid;
    }
};
// @lc code=end
