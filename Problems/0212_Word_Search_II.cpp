class Trie{
public:
    Trie* children[26];
    bool isend;
    
    Trie(){
        isend = false;
        for(int i=0;i<26;i++) children[i] = nullptr;
    }
    
    ~Trie(){
        for(int i = 0;i<26;i++) if(children[i]) delete children[i];
    }
    
    void insert(string word){
        Trie* curr = this;
        for(char x:word){
            if(!curr->children[x-'a']) curr->children[x-'a'] = new Trie();
            curr = curr->children[x-'a'];
        }
        curr->isend = true;
    }
};

class Solution {
public:
    bool check(int i,int j,int r,int c){
        return i>=0 && i<r && j>=0 && j<c;
    }
    
    void dfs(vector<vector<char>>& board,int i,int j,unordered_set<string>& ans,string s, Trie* t){
        char c = board[i][j];
        if(c == '$') return;
        board[i][j] = '$';
        Trie* tr = t->children[c-'a'];
        if(tr){
            string ns = s + c;
            vector<pair<int,int>>dirs = {{-1,0},{0,-1},{1,0},{0,1}};
            if(tr->isend) ans.insert(ns);
            for(auto dir: dirs){
                int ii = i+dir.first,jj = j+dir.second;
                if(check(ii,jj,board.size(),board[0].size())){
                    dfs(board,ii,jj,ans,ns,tr);
                }
            }
        }
        board[i][j] = c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(words.size() == 0) return{};
        Trie t;
        for(string s: words){
            t.insert(s);
        }
        unordered_set<string>ans;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                dfs(board,i,j,ans,"",&t);
            }
        }
        vector<string> fans(ans.begin(),ans.end());
        return fans;
    }
};