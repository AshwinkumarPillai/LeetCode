// Optimized Loop 2 pointers
class Solution {
public:  
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *trav1= headA, *trav2 = headB;
        while(trav1!=trav2){
            trav1 = (trav1 == nullptr ) ? headB : trav1->next;
            trav2 = (trav2 == nullptr ) ? headA : trav2->next;
        }
        return trav1;
    }
};

// Traversing till tail and checking both
class Solution {
public:  
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a=0,b=0;
        ListNode *trav1= headA, *trav2 = headB;
        while(trav1){
            a++;
            trav1 = trav1->next;
        }
        while(trav2){
            b++;
            trav2 = trav2->next;
        }
        trav1 = (a>=b) ? headA : headB;
        trav2 = (a<b) ? headA : headB;
        int diff = abs(a-b);
        for(int i=0;i<diff;i++){
            trav1 = trav1->next;
        }
        while(trav1){
            if(trav1 == trav2) return trav1;
            trav1 = trav1->next;
            trav2 = trav2->next;
        }
        return NULL;
    }
};

// Using Set
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*>s;
        while(headA){
            s.insert(headA);
            headA = headA->next;
        }
        while(headB){
            if(s.find(headB) != s.end()) return headB;
            headB = headB->next;
        }
        return NULL;
    }
};
