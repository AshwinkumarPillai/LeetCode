class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *node1 = l1;
        ListNode *node2 = l2;
        int carry = 0;

        ListNode *node = NULL;
        ListNode *temp = NULL;
        ListNode *head = NULL;

        int n = node1->val + node2->val;
        if (n > 9)
        {
            carry = 1;
        }

        node = new ListNode(n % 10);
        head = node;
        node1 = node1->next;
        node2 = node2->next;
        while (node1 != NULL && node2 != NULL)
        {
            n = node1->val + node2->val + carry;
            if (n > 9)
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            temp = new ListNode(n % 10);
            node->next = temp;
            node = temp;
            node1 = node1->next;
            node2 = node2->next;
        }

        if (node2 != NULL)
        {
            while (node2 != NULL)
            {
                n = node2->val + carry;
                if (n > 9)
                {
                    carry = 1;
                }
                else
                {
                    carry = 0;
                }
                temp = new ListNode(n % 10);
                node->next = temp;
                node = temp;
                node2 = node2->next;
            }
        }

        if (node1 != NULL)
        {
            while (node1 != NULL)
            {
                n = node1->val + carry;
                if (n > 9)
                {
                    carry = 1;
                }
                else
                {
                    carry = 0;
                }
                temp = new ListNode(n % 10);
                node->next = temp;
                node = temp;
                node1 = node1->next;
            }
        }

        if (carry == 1)
        {
            temp = new ListNode(1);
            temp->next = NULL;
            node->next = temp;
        }

        return head;
    }
};