class Solution
{
    Node *recursion(Node *start)
    {
        Node *current = start;
        Node *tail = nullptr;

        while (current)
        {
            Node *nextnode = current->next;
            if (current->child)
            {

                Node *childtail = recursion(current->child);

                current->next = current->child;
                current->child->prev = current;

                if (nextnode)
                {
                    childtail->next = nextnode;
                    nextnode->prev = childtail;
                }
                current->child = nullptr;
                tail = childtail;
            }
            else
            {
                tail = current;
            }
            current = nextnode;
        }
        return tail;
    }

public:
    Node *flatten(Node *head)
    {
        if (!head)
            return nullptr;
        recursion(head);
        return head;
    }
};
