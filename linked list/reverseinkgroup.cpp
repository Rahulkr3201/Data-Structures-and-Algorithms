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
    // Reverse a linked list
    ListNode *reverseLinkedList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Get the k-th node from current node
    ListNode *getKthNode(ListNode *temp, int k)
    {
        k -= 1;
        while (temp != nullptr && k > 0)
        {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *temp = head;
        ListNode *prevLast = nullptr;

        while (temp != nullptr)
        {
            ListNode *kthNode = getKthNode(temp, k);
            if (kthNode == nullptr)
            {
                if (prevLast)
                {
                    prevLast->next = temp;
                }
                break;
            }

            ListNode *nextNode = kthNode->next;
            kthNode->next = nullptr;

            // Reverse current k-group
            ListNode *reversedHead = reverseLinkedList(temp);

            if (temp == head)
            {
                head = reversedHead;
            }
            else
            {
                prevLast->next = reversedHead;
            }

            prevLast = temp;
            temp = nextNode;
        }

        return head;
    }
};
