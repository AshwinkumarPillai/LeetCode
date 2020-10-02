class Trie {
private:
    class Node{
        public:
            unordered_map<char,Node*> children;
            bool isend;
            Node(){
                isend = false;
            }
    };
    
public:
    Node* root = NULL;
    
    Trie() {
        // root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;
        if(root == NULL){
            root = new Node();
            node = root;
            for(char s: word){
                node->children[s] = new Node();
                node = node->children[s];
            }
        }else{
            for(char s: word){
                if(node->children.find(s) == node->children.end()){
                    node->children[s] = new Node();
                }
                node = node->children[s];
            }
        }
        node->isend = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(root == NULL){
            return false;
        }
        Node* node = root;
        for(char s: word){
            if(node->children.find(s) == node->children.end()){
                return false;
            }
            node = node->children[s];
        }
        if(node->isend){
            return true;
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(root == NULL){
            return false;
        }
        Node* node = root;
        for(char s: prefix){
            if(node->children.find(s) == node->children.end()){
                return false;
            }
            Node* child = node->children[s];
            node = child;
        }
        return true;
    }
};