// Two pointer approach
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        set<int>s;
        int i = 0, j=0, n= nums.size();
        int ans = 0, maxAns = 0;
        while(i<n && j <n){
            if(s.find(nums[j]) == s.end()){
             ans += nums[j];
             s.insert(nums[j]);
             j++;
             maxAns = max(ans, maxAns);
          }
          else{
              ans -= nums[i];
              s.erase(nums[i]);
              i++;
          }
        }
        return maxAns;
    }
};