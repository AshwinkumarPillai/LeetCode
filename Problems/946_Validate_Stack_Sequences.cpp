class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i = 0, n= popped.size();
        
        for(int x: pushed){
            st.push(x);
            while(!st.empty() && i<n && popped[i] == st.top()){
               st.pop();
                i++;
            }
        }
        
        return i == n;
    }
};
