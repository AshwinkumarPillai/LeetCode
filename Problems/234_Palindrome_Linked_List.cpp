
// Approach 1: Use an extra array to store list
// Time - O(n) | Space - O(n) 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int>l;
        ListNode* trav = head;
        while(trav){
            l.push_back(trav->val);
            trav = trav->next;
        }
        int i = 0,j = l.size() - 1;
        while(i<=j){
            if(l[i] != l[j]) return false;
            i++;j--;
        }
        return true;
    }
};

// Aproach 2: Reverse Linked List and check
// Time - O(n) | Space - O(n)
class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode* node = NULL;
        ListNode* trav = head;
        while(trav){
            node = new ListNode(trav->val, node);
            trav = trav->next;
        }
        return node;
    }
    
    bool isPalindrome(ListNode* head) {       
        ListNode* trav = head;
        ListNode* rev = reverseList(head);
        while(trav){
            if(trav->val != rev->val) return false;
            trav = trav->next;
            rev = rev->next;
        }
        return true;
    }
};


// Aproach 3: Reverse Half and check 2 pointers + stack
// Insert value of slow to stack and when fast hits end check slow with elements of stack
// Time - O(n) | Space - O(n)
class Solution {
public:
    
    bool isPalindrome(ListNode* head) {       
        stack<int>s;
        ListNode* fast = head, *slow = head;
        while(fast && fast->next){
            s.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast) slow = slow->next;
        while(slow){
            int top = s.top();s.pop();
            if(slow->val != top) return false;
            slow = slow->next;
        }
        return true;
    }
};
