// Explanation - https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/discuss/754623/Detailed-Explanation

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = target[0],n=target.size();
        for(int i=1;i<n;i++) if(target[i] > target[i-1]) ans += target[i] - target[i-1];
        return ans;
    }
};
