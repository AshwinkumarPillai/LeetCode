// Using count | Time - O(N) | Space - O(1)
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        int count = 0;
        
        // Remove unwanted closed brackets
        for(int i=0;i<n;i++){
            if(s[i] == ')'){
                if(count == 0) s[i] = '*';
                else count--;
            }else if(s[i] == '('){
                count++;
            }
        }
        
        count = 0;
        
        // Remove unwanted open bracktes
        for(int i = n-1;i>=0;i--){
            if(s[i] == '('){
                if(count == 0) s[i] = '*';
                else count--;
            }else if(s[i] == ')'){
                count++;
            }
        }
        
        string ans = "";
        for(char x: s){
            if(x != '*') ans.push_back(x);
        }
        return ans;
    }
};

// Using Stack | Time - O(N) | Space - O(N)
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // stack to keep track of indices of '('
        stack<int>st;
        
        int n = s.length();
        
        for(int i = 0;i < n;i++){
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')'){
                if(st.empty()) s[i] = '*';
                else st.pop();
            }
        }
        
        while(!st.empty()){
            s[st.top()] = '*';
            st.pop();
        }
        
        string ans = "";
        for(char x: s){
            if(x != '*') ans.push_back(x);
        }
        return ans;
    }
};
