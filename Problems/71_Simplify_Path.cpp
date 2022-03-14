// Using vector
class Solution {
public:
    
    string simplifyPath(string path) {
        istringstream ss(path);
        string token;
        
        vector<string> st;
        
        while(getline(ss, token, '/')){
            if(token == "" || token == ".") continue;
            else if(token == ".."){
                if(st.size()) st.pop_back();
            }
            else st.emplace_back(token);
        }
        
        string ans = "";
        
        for(string x: st){
            ans += "/" + x;
        }
        
        return ans != "" ? ans : "/";
    }
};

// Using stack
class Solution {
public:
    
    string simplifyPath(string path) {
        istringstream ss(path);
        string token;
        
        stack<string> st;
        
        while(getline(ss, token, '/')){
            if(token == "" || token == ".") continue;
            else if(token == ".."){
                if(!st.empty()) st.pop();
            }
            else st.push(token);
        }
        
        string ans = "";
        
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }
        
        return ans != "" ? ans : "/";
        
    }
};
