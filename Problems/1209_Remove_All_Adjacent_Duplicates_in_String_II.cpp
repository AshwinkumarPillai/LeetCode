// Using Vector with stack like implementation | Time - O(N) | Space - O(N)
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