// Time - O(n) Space - O(n) -- Use array of possible values
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(),one=0;
        for(int x: nums){
            if(x == 1){
                one = 1;
                break;
            }
        } 
        if(!one) return 1;
        if(n == 1) return 2;
        vector<int>contains(n+1);
        for(int &x: nums)
            if(x <=0 || x > n) x = 1;
        for(int x: nums) contains[x]++;
        for(int i=1;i<n+1;i++) if(!contains[i]) return i;
        return n+1;
    }
};

// Time - O(nlogn) Space - O(1) -- Sort and check
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0,n = nums.size();
        int ans = 1;
        while(i < n && nums[i] <= 0) i++;
        while(i < n && nums[i]<= ans){
            ans = nums[i]+1;
            i++;
        }
        return ans;
    }
};
