class Solution {
public:
    
    vector<int>globalAlpha;
    
    void fillAlpha(vector<string>& B){
        for(string b: B){
            vector<int> localAlpha(26);
            for(char x: b){
                localAlpha[x - 'a']++;
            }
            for(int i=0;i<26;i++) globalAlpha[i] = max(globalAlpha[i],localAlpha[i]);
        }
    }
    
    bool hasAll(string& s){
        vector<int> localAlpha(26);
        for(char x: s){
            localAlpha[x-'a']++;
        }
        for(int i=0;i<26;i++){
            if(globalAlpha[i] > localAlpha[i]) return false;
        }
        return true;
    }
    
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        globalAlpha.resize(26);
        fillAlpha(B);
        vector<string> ans;
        for(string s: A){
            if(hasAll(s)){
                ans.push_back(s);
            }
        }
        return ans;
    }
};
