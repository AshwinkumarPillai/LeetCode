class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *odd = head;
        if (odd == NULL)
        {
            return head;
        }
        ListNode *even = head->next;
        if (even == NULL)
        {
            return head;
        }
        ListNode *temp = even;

        while (even != NULL)
        {
            odd->next = even->next;
            if (odd->next == NULL)
            {
                break;
            }
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = temp;
        if (even != NULL)
        {
            even->next = NULL;
        }
        return head;
    }
};