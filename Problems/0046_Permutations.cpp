// Backtracking
class Solution {
public:
    vector<vector<int>>ans;
    int n;
    void perm(vector<int>& nums,int curr){
        if(curr == n - 1){
            ans.push_back(nums);
            return;
        }
        for(int i= curr;i<n;i++){
            swap(nums[i],nums[curr]);
            perm(nums,curr+1);
            swap(nums[i],nums[curr]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();
        n = nums.size();
        perm(nums,0);
        return ans;
    }
};

// using built-in function
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        ans.push_back(nums);
        while(next_permutation(nums.begin(),nums.end())){
            ans.push_back(nums);
        }
        return ans;
    }
};
