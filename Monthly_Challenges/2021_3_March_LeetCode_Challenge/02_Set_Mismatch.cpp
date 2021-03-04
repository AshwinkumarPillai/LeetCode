// Using XOR
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int xr = 0,xorSet = 0,xorUnset = 0,n=nums.size();
        for(int i=1;i<=n;i++) xr ^= i;
        for(int x:nums) xr ^= x;
        int rightMostSetBit = xr & ~(xr-1);
        for(int x: nums){
            if((x & rightMostSetBit) == 0) xorUnset ^= x;
            else xorSet ^= x;
        }
        for(int i=1;i<=n;i++){
            if((i & rightMostSetBit) == 0) xorUnset ^= i;
            else xorSet ^= i;
        }
        for(int x: nums){
            if(x == xorSet) return {x,xorUnset};
        }
        return {xorUnset, xorSet};
    }
};


// Using constant space
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup=0,missing=0,n=nums.size();
        for(int x:nums){
            if(nums[abs(x)-1] < 0) dup = abs(x);
            else nums[abs(x) -1] *= -1;
        }
        for(int i=0;i<n;i++){
            if(nums[i] > 0) missing = i+1;
        }
        return {dup,missing};
    }
};

// Using another array
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ans = {0,0};
        int n = nums.size();
        vector<int> s(n+1);
        for(int x:nums){
            s[x]++;
        }
        
        for(int i=1;i<n+1;i++){
            if(s[i] == 0) ans[1] = i;
            else if(s[i] == 2) ans[0] = i;
        }
        return ans;
    }
};
