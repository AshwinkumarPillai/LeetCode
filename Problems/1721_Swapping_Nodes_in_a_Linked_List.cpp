// Three Pointer - Single pass
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* left = nullptr, *right = nullptr, *trav = head;
        while(trav){
            if(right) right = right->next;
            if(--k == 0){
                left = trav;
                right = head;
            }
            trav = trav->next;
        }
        swap(left->val,right->val);
        return head;
    }
};

// O(1) space
class Solution {
public:
    ListNode* getKthNode(ListNode* node,int n){
        ListNode* trav = node;
        int i = 1;
        while(i<n){
            trav = trav->next;
            i++;
        }
        return trav;
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* kf = getKthNode(head,k);
        ListNode* trav = head;
        int n= 0;
        while(trav){
            trav = trav->next;
            n++;
        }
        ListNode* kb = getKthNode(head,n-k+1);
        int temp = kf->val;
        kf->val = kb->val;
        kb->val = temp;
        return head;
    }
};

// Using Array
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int>arr;
        ListNode* trav = head;
        int n = 0;
        while(trav){
            arr.push_back(trav->val);
            trav = trav->next;
            n++;
        }
        swap(arr[k-1],arr[n-k]);
        trav = head;
        for(int x: arr){
            trav->val = x;
            trav = trav->next;
        }
        return head;
    }
};
