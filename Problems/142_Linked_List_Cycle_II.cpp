class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head, *slow = head;
        while(fast &&  fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast) break;
        }
        if(!fast || !fast->next) return NULL;
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
