class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char,bool> jewel;
        for(char x: J){
            jewel[x] = true;
        }
        int ans = 0;
        for(char x: S){
            if(jewel.find(x) != jewel.end()){
                ans++;
            }
        }
        return ans;
    }
};