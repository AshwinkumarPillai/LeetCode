class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(char x: s){
            if(x == '{' || x == '[' || x == '(') st.push(x);
            else{
                if(st.empty()) return false;
                char t = st.top();
                if((x == '}') && (t != '{')) return false;
                else if((x == ')') && (t != '(')) return false;
                else if(x == ']' && t != '[') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
