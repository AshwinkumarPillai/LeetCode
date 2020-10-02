class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* trav = head,*prev = NULL;
        while(trav){
            ListNode* next = trav->next;
            int flag = 0;
            while(next && next->val == trav->val){
                trav = next;
                next = next->next;
                flag =1;
            }
            if(flag){
                if(prev) prev->next = next;
                else{
                    head = next;
                }
            }else{
                prev = trav;
            }
            trav = next;
        }
        return head;
    }
};
