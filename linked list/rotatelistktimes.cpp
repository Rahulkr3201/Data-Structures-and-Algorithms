class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
            return head;

        ListNode *temp = head;
        ListNode *last = head;
        int length = 1;

        while (temp->next != NULL)
        {
            temp = temp->next;
            length++;
        }
        last = temp;

        k = k % length;
        if (k == 0)
            return head;

        int first = length - k;
        ListNode *newTail = head;

        for (int i = 0; i < first - 1; i++)
        {
            newTail = newTail->next;
        }

        ListNode *newHead = newTail->next;
        newTail->next = NULL;
        last->next = head;

        return newHead;
    }
};
