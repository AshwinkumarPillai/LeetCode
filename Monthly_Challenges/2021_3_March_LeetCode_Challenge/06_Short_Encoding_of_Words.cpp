// Remove Suffixes
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string>s;
        for(string x: words) s.insert(x);
        for(string word: words){
            for(int i=1;i<word.length();i++){
                s.erase(word.substr(i));
            }
        }
        int ans = 0;
        for(string x: s){
            ans += x.length() + 1;
        }
        return ans;
    }
};
