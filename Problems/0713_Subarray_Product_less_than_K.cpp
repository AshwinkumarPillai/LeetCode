class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int product = 1,ans = 0,l = 0,n = nums.size();
        for(int r = 0;r<n;r++){
            product *= nums[r];
            while(product >= k) product /= nums[l++];
            ans += (r - l + 1);
        }
        return ans;
    }
};
