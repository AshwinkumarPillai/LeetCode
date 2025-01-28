// 1-pass
class Solution {
public:
    string getHint(string s, string g) {
        int n = s.length();
        int a=0,b=0;
        vector<int>arr(10);
        for(int i=0;i<n;i++){
            char x = s[i];
            char y = g[i];
            if(x == y) a++;
            else{
                if(arr[x -'0'] < 0) b++;
                if(arr[y -'0'] > 0) b++;
                arr[x - '0']++;
                arr[y - '0']--;
            }
        }
        string ans = to_string(a) + "A" + to_string(b) + "B";
        return ans;
    }
};

// 2-pass
class Solution {
public:
    string getHint(string s, string g) {
        int n = s.length();
        int a=0,b=0;
        unordered_map<char,int>m;
        for(char x: s) m[x]++;
        for(int i=0;i<n;i++){
            char x = g[i];
            if(m.find(x) != m.end()){
                if(s[i] == x){
                    a++;
                    if(m[x] <= 0) b--;
                }else if(m[x] > 0) b++;
                m[x]--;
            }
        }
        string ans = to_string(a) + "A" + to_string(b) + "B";
        return ans;
    }
};

// 3-pass
class Solution {
public:
    string getHint(string s, string g) {
        int n = s.length();
        int a=0,b=0;
        unordered_map<char,int>m;
        for(char x: s) m[x]++;
        for(int i=0;i<n;i++){
            if(g[i] == s[i]){
                if(--m[s[i]] == 0) m.erase(s[i]);
                a++;
            }
        }
        for(int i=0;i<n;i++){
            if(g[i] != s[i]){
                if(m.find(g[i]) != m.end()){
                    if(--m[g[i]] == 0) m.erase(g[i]);
                    b++;
                }
            }
        }
        string ans = to_string(a) + "A" + to_string(b) + "B";
        return ans;
    }
};
