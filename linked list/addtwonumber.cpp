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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *current = dummy;

        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        int carry = 0;
        while (temp1 != NULL || temp2 != NULL || carry != 0)
        {
            int sum = carry;

            if (temp1 != NULL)
            {
                sum = sum + temp1->val;
                temp1 = temp1->next;
            }

            if (temp2 != NULL)
            {
                sum = sum + temp2->val;
                temp2 = temp2->next;
            }
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }
        return dummy->next;
    }
};