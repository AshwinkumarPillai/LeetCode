// // DP - O(n)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        int x,minval = nums[0],maxval = nums[0],ans = nums[0];
        for(int i=1;i<n;i++){
            x = nums[i];
            if(x < 0) swap(minval,maxval);
            minval = min(minval * x,x);
            maxval = max(maxval * x,x);
            ans = max(ans,maxval);
        }
        return ans;
    }
};  
    
// Brute Force 
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        int ans = nums[0];
        for(int i=0;i<n;i++){
            int prod = 1;
            for(int j=i;j<n;j++){
                prod *= nums[j];
                ans = max(ans,prod);
            }
        }
        return ans;
    }
};
