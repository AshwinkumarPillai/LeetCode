class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>lastIndex(26);
        vector<bool>isCharInStack(26);
        int n = s.length();
        for(int i=0;i<n;i++){
            lastIndex[s[i] - 'a'] = i;
        }
        vector<char>st;
        for(int i=0;i<n;i++){
            if(st.size() == 0){
                st.emplace_back(s[i]);
                isCharInStack[s[i] - 'a'] = true;
            }
            else if(!isCharInStack[s[i] - 'a']){
                while(st.size() > 0 && i < lastIndex[st.back() - 'a'] && s[i] < st.back()){
                    isCharInStack[st.back() - 'a'] = false;
                    st.pop_back();
                }
                st.emplace_back(s[i]);
                isCharInStack[s[i] - 'a'] = true;
            }
        }
        
        string ans = "";
        
        for(char x: st){
            ans.push_back(x);
        }
        
        return ans;
    }
};
