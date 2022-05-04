// Sort - Two Sum Soln | Time - O(nlogn) | Space - O(1)
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1, ans = 0;
        
        while(i<j){
            int val = nums[i] + nums[j];
            if(val == k) {
                ans++;
                i++;
                j--;
            }
            else if(val < k) i++;
            else j--;
        }
        
        return ans;
    }
};

// Using Map | Time - O(n) | Space - O(n)
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int> m;
        
        for(int x: nums){
            int rem = k - x;
            if(m[rem] > 0){
                ans++;
                m[rem]--;
            }else m[x]++;
        }
        
        return ans;
    }
};