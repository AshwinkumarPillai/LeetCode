class Solution {
public:
    void backtrack(int n,int k,vector<int>& comb,int i,vector<vector<int>>& ans){
        if(n == 0 && comb.size() == k){
            ans.push_back(comb);
            return;
        }
        if(n < 0 || comb.size() == k) return;
        for(int j=i+1;j<10;j++){
            comb.push_back(j);
            backtrack(n-j,k,comb,j,ans);
            comb.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>comb;
        backtrack(n,k,comb,0,ans);
        return ans;
    }
};
