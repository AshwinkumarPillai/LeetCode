// 1. Find middle - 2. Reverse the second part from middle - 3. merge ll
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        //Find the middle of the linked list - slow will be middle Node
        ListNode* slow = head,*fast=head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        //Revese the second part - prev will the head of the reversed list
        ListNode *prev = NULL,*curr=slow,*next;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr=next;
        }
        //Merge the two list
        ListNode* first = head,*second = prev;
        while(second->next){
            next = first->next;
            first->next = second;
            first = next;
            
            next = second->next;
            second->next = first;
            second = next;
        }
    }
};

// O(N) space approach  - Initial approach
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head) return;
        vector<ListNode*>list;
        ListNode*trav = head;
        while(trav){
            list.push_back(trav);
            trav = trav->next;
        }
        
        int n = list.size();
        int l = 0,r=n-1;
        while(l<r){
            list[l++]->next = list[r];
            list[r--]->next = list[l];
        }
        list[(n)/2]->next = NULL;
    }
};
