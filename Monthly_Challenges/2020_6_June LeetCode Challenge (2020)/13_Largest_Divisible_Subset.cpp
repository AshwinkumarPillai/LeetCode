class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || n==0){
            return nums;
        }
        sort(nums.begin(),nums.end());
        vector<int> maxDiv(n,1);
        vector<int> chain(n,-1);
        pair<int,int> maxval = {1,0};
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j] == 0){
                    if(maxDiv[j]+1 > maxDiv[i]){
                        maxDiv[i] = maxDiv[j]+1;
                        chain[i] = j;
                    }
                }
            }
            if(maxDiv[i] > maxval.first){
                maxval = {maxDiv[i],i};
            }
        }
        int index = maxval.second;
        vector<int>ans;
        while(index>=0){
            ans.emplace_back(nums[index]);
            index = chain[index];
        }
        return ans;
    }
};