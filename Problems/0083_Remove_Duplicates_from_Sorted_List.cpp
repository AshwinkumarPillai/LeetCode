class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* trav = head;
        while(trav){
            ListNode* curr = trav;
            trav = trav->next;
            while(trav && (trav->val == curr->val)){
                trav = trav->next;
            }
            curr->next = trav;
        }
        return head;
    }
};
