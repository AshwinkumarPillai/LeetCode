class Solution {
public:
    
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        Node* trav = head;
        while(trav){
            Node* newNode = new Node(trav->val);
            m[trav] = newNode;
            trav = trav->next;
        }
        
        for(auto p: m){
            p.second->next = p.first->next != NULL ?m[p.first->next] : NULL;
            p.second->random = p.first->random != NULL ? m[p.first->random] : NULL;
        }
        
        return m[head];
    }
};
