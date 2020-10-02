class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int k)
    {
        ListNode *first = head;
        ListNode *second = head;
        for (int i = 0; i < k; i++)
        {
            first = first->next;
        }

        while (first != NULL)
        {
            second = second->next;
            first = first->next;
        }
        if (second == head)
        {
            head = second->next;
            return head;
        }
        if (second->next)
        {
            second->val = second->next->val;
            second->next = second->next->next;
        }
        else
        {
            ListNode *trav = head;
            while (trav->next != second)
            {
                trav = trav->next;
            }
            trav->next = NULL;
        }
        return head;
    }
};