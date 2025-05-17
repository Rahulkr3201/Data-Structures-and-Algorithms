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
        ListNode *dummy1 = new ListNode(-1);
        ListNode *dummy = dummy1;

        ListNode *temp1 = list1;
        ListNode *temp2 = list2;
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->val <= temp2->val)
            {
                dummy->next = temp1;
                dummy = temp1;
                temp1 = temp1->next;
            }
            else
            {
                dummy->next = temp2;
                dummy = temp2;
                temp2 = temp2->next;
            }
        }
        if (temp1 == NULL)
        {
            while (temp2 != NULL)
            {
                dummy->next = temp2;
                dummy = temp2;
                temp2 = temp2->next;
            }
        }
        else if (temp2 == NULL)
        {
            while (temp1 != NULL)
            {
                dummy->next = temp1;
                dummy = temp1;
                temp1 = temp1->next;
            }
        }
        return dummy1->next;
    }
};