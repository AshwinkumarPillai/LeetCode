class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, int>lastIndex;
        map<char, bool>isCharInStack;
        int n = s.length();
        for(int i=0;i<n;i++){
            lastIndex[s[i]] = i;
        }
        vector<char>st;
        for(int i=0;i<n;i++){
            if(st.size() == 0){
                st.emplace_back(s[i]);
                isCharInStack[s[i]] = true;
            }
            else if(!isCharInStack[s[i]]){
                while(st.size() > 0 && i < lastIndex[st.back()] && s[i] < st.back()){
                    isCharInStack[st.back()] = false;
                    st.pop_back();
                }
                st.emplace_back(s[i]);
                isCharInStack[s[i]] = true;
            }
        }
        
        string ans = "";
        
        for(char x: st){
            ans.push_back(x);
        }
        
        return ans;
    }
};