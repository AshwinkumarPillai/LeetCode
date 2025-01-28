class Solution {
public:
    vector<vector<string>> vals = {{"a", "b", "c"}, {"d", "e", "f"}, {"g", "h", "i"}, {"j", "k", "l"}, {"m", "n", "o"}, {"p", "q", "r", "s"}, {"t","u", "v"}, {"w", "x", "y", "z"}};
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string>ans = {""};
        
        for(char x: digits){
            vector<string>temp;
            for(string y: vals[x - '2']){
                for(string s: ans){
                    temp.push_back(s + y);
                }
            }
            swap(temp, ans);
        }
        return ans;
    }
};