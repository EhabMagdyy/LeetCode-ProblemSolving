/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (nullptr == list1 && nullptr == list2)
            return nullptr;

        ListNode *mergedList = new ListNode();
        ListNode *ptr = mergedList;

        while (nullptr != list1 && nullptr != list2)
        {
            if (list1->val < list2->val)
            {
                ptr->val = list1->val;
                if (nullptr != list1->next || nullptr != list2 || nullptr != list2->next)
                {
                    ptr->next = new ListNode();
                    ptr = ptr->next;
                }
                list1 = list1->next;
            }
            else
            {
                ptr->val = list2->val;
                if (nullptr != list1->next || nullptr != list1 || nullptr != list2->next)
                {
                    ptr->next = new ListNode();
                    ptr = ptr->next;
                }
                list2 = list2->next;
            }
        }
        while (nullptr != list1)
        {
            ptr->val = list1->val;
            if (nullptr != list1->next)
            {
                ptr->next = new ListNode();
                ptr = ptr->next;
            }
            list1 = list1->next;
        }
        while (nullptr != list2)
        {
            ptr->val = list2->val;
            if (nullptr != list2->next)
            {
                ptr->next = new ListNode();
                ptr = ptr->next;
            }
            list2 = list2->next;
        }

        return mergedList;
    }
};
// @lc code=end
