class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        ListNode *beforeHead = new ListNode();
        ListNode *afterHead  = new ListNode();
        ListNode *before = beforeHead, *after = afterHead, *trav = head;
        while(trav){
            if(trav->val < x){
                before->next = trav;
                before = before->next;
            }else{
                after->next = trav;
                after = after->next;
            }
            trav = trav->next;
        }
        
        after->next = NULL;
        before->next = afterHead->next;
        return beforeHead->next;
    }
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        vector<int>less,more;
        ListNode* trav = head;
        while(trav){
            if(trav->val < x) less.push_back(trav->val);
            else more.push_back(trav->val);
            trav = trav->next;
        }
        if(less.size() > 0) {
            head = new ListNode(less[0]);
            trav = head;
        }
        for(int i=1;i<less.size();i++){
            ListNode* node = new ListNode(less[i]);
            trav->next = node;
            trav = node;
        }
        if(less.size() == 0){
            head = new ListNode(more[0]);
            trav = head;
        }else if(more.size() == 0){
            return head;
        }else{
            ListNode* node = new ListNode(more[0]);
            trav->next = node;
            trav = node;
        }
        for(int i=1;i<more.size();i++){
            ListNode* node = new ListNode(more[i]);
            trav->next = node;
            trav = node;
        }
        return head;
    }
};
