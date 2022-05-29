// Using Bitset - perform AND op to check if comon exists
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0, n = words.size();
        vector<bitset<26>> masks(n);
        for(int i = 0; i< n;i++){
            for(char x: words[i]){
                masks[i][x - 'a'] = 1;
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = i+1;j < n; j++){
                if((masks[i] & masks[j]) == 0){
                    int val = words[i].length() * words[j].length();
                    ans = max(val, ans);
                }
            }
        }
        return ans;
    }
};