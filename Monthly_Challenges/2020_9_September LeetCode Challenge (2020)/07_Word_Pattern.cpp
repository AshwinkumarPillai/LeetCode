// 0ms solution
class Solution {
public:
    bool isDiff(vector<int>& a,vector<int>& b){
        if(a.size() != b.size()) return true;
        int n = a.size();
        for(int i=0;i<n;i++){
            if(a[i] != b[i]) return true;
        }
        return false;
    }
    
    bool wordPattern(string pattern, string str) {
        set<char>s;
        vector<string>b;
        unordered_map<char,vector<int>>m1;unordered_map<string,vector<int>>m2;
        int n = pattern.size(),count=0;
        for(int i = 0;i<n;i++){
            char x = pattern[i];
            s.insert(x);
            m1[x].push_back(i);
        }
        istringstream iss(str);
        string word;
        while(iss>>word){
            b.push_back(word);
            m2[word].push_back(count++);
        }
        if(m1.size() != m2.size() || pattern.length() != b.size()) return false;
        for(int i=0;i<n;i++){
            char x = pattern[i];
            if(s.find(x) != s.end()){
                if(isDiff(m1[x],m2[b[i]])) return false;
                s.erase(x);
            }
            if(s.empty()) break;
        }
        return true;
    }
};

// 2-map check
class Solution {
public:    
    bool wordPattern(string pattern, string str) {
        unordered_map<char,string>m;unordered_map<string,char>m2;
        vector<string>words;
        istringstream iss(str);
        string word;
        while(iss>>word) words.push_back(word);
        int n = pattern.length();
        if(words.size() != n) return false;
        for(int i=0;i<n;i++){
            char x = pattern[i];
            word = words[i];
            if(m.find(x) == m.end()){
                if(m2.find(word) != m2.end()) return false;
                m[x] = word;
                m2[word] = x;
            }else if(m[x] != word) return false;
        }
        return true;
    }
};

// 1-map and index
class Solution {
public:    
    bool wordPattern(string pattern, string str) {
        unordered_map<string,int>m;
        vector<string>words;
        istringstream iss(str);
        string word;
        while(iss>>word) words.push_back(word);
        int n = pattern.length();
        if(words.size() != n) return false;
        for(int i=0;i<n;i++){
            string x = to_string(pattern[i]);
            word = words[i];
            if(m.find(x) == m.end()) m[x] = i;
            if(m.find(word) == m.end()) m[word] = i;
            if(m[x] != m[word]) return false;
        }
        return true;
    }
};
