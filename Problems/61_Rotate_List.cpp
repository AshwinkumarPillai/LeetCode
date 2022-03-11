class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;
        int n = 1;
        ListNode* trav = head;
        while(trav->next){
            n++;
            trav = trav->next;
        }
        k = k % n;
        if(k == 0) return head;
        
        ListNode* newHead = head;
        ListNode* tail = NULL;
        for(int i=0;i<n-k;i++){
            tail = newHead;
            newHead = newHead->next;
        }

        tail->next = NULL;
        trav->next = head;
        return newHead;  
    }
};
