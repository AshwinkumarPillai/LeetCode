class Trie{
public:
    map<char,Trie*> children;
    bool isend;
    Trie(){
        isend = false;
    }
};

class StreamChecker {
public:
    Trie *root = new Trie();
    deque<char> stream;
    
    StreamChecker(vector<string>& words) {
        for(string word: words){
            Trie* node = root;
            reverse(word.begin(),word.end());
            for(char x: word){
                if(!node->children.count(x)){
                    node->children[x] = new Trie();
                }
                node = node->children[x];
            }
            node->isend = true;
        }    
    }
    
    bool query(char letter) {
        stream.push_front(letter);
        Trie* node = root;
        for(char x: stream){
            if(node->isend) return true;
            if(!node->children[x]) return false;
            node = node->children[x];
        }
        return node->isend;
    }
};
