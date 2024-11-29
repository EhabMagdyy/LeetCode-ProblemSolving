/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *result = new ListNode();
        ListNode *ptr = result;
        int sum = 0;
        while (l1 != nullptr || l2 != nullptr)
        {
            if (l1 != nullptr) sum += l1->val;
            if (l2 != nullptr) sum += l2->val;
            ptr->val = sum;
            ptr->val = sum % 10;
            ptr->next = nullptr;
            sum /= 10;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
            if (l1 != nullptr || l2 != nullptr)
            {
                ptr->next = new ListNode();
                ptr = ptr->next;
            }
        }
        if (sum) ptr->next = new ListNode(sum, nullptr);

        return result;
    }
};

// @lc code=end
