class WordDictionary {
private:
    class Node{
        public:
            map<char,Node*>children;
            bool isend;
            Node(){
                isend = false;
            }
    };
public:
    /** Initialize your data structure here. */
    Node* root = NULL;
    
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node* node = root;
        if(!root){
            root = new Node();
            node = root;
            for(char c: word){
                node->children[c] = new Node();
                node = node->children[c];
            }
        }else{
            for(char c: word){
                if(node->children.find(c) == node->children.end()){
                    node->children[c] = new Node();
                }
                node = node->children[c];
            }
        }
        node->isend = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool checkChild(string word,Node* node){
        for(int i=0;i<word.length();i++){
            char c = word[i];
            if(node->children.find(c) == node->children.end()){
                if(c == '.'){
                    for(auto p: node->children){
                        if(checkChild(word.substr(i+1),p.second)) return true;
                    }
                }
                return false;
            }
            node = node->children[c];
        }
        return node->isend;
    }
    
    bool search(string word) {
        if(!root) return false;
        return checkChild(word,root);
    }
};

