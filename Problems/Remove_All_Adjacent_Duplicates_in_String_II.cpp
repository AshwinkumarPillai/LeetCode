// Approach 1 - Using Vector with stack like implementation | Time - O(N) | Space - O(N)
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> arr;
        for(char x: s){
            if((arr.size() > 0) && (arr.back().first == x)){
                arr.push_back({x, arr.back().second + 1});
                if(arr.back().second == k){
                    for(int i = 0;i<k;i++) arr.pop_back();
                }
            }
            else if((arr.size() == 0)|| (arr.back().first != x)) arr.push_back({x, 1});
        }
        string ans = "";
        for(pair<char, int> p: arr) ans.push_back(p.first);
        return ans;
    }
};

// Apporach 2 - Refined approach 1 | Time - O(N) | Space - O(N)
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> arr;
        for(char x: s){
            if(arr.empty() || arr.back().first != x) arr.push_back({x, 0});
            if(++arr.back().second == k) arr.pop_back();
        }
        string ans = "";
        for(pair<char, int>& p: arr) ans += string(p.second, p.first);
        return ans;
    }
};

// Approach 3 - Two Pointers | Time - O(N) | Space - O(N)
class Solution {
public:
    string removeDuplicates(string s, int k) {
        int j = 0, n = s.length();
        vector<int> count(n, 1);
        for (int i = 0; i < n; i++, j++){
            s[j] = s[i];
            if(j >  0 && s[j] == s[j-1]) count[j] = count[j-1] + 1;
            else count[j] = 1;
            if(count[j] == k) j-=k;
        }
        return s.substr(0, j);
    }
};
