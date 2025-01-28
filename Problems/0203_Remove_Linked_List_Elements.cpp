class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)return head;
        while(head && head->val == val) head = head->next;
        ListNode* trav = head;
        ListNode* prev = NULL;
        while(trav){
            prev = trav;
            while(trav->next && trav->next->val == val){
                trav = trav->next;
            }
            prev->next = trav->next;
            trav=trav->next;
        }
        return head;
    }
};