// Prefix sum and map
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0,n=nums.size();
        if(!n) return 0;
        int sum = 0;
        unordered_map<int,int> cpref;      
        for(int x: nums){
            sum +=x;
            if(sum == k) 
                ans++;
            if(cpref.find(sum-k) != cpref.end())
                ans+=cpref[sum-k];
            if(cpref.find(sum) != cpref.end()) 
                cpref[sum]++;
            else 
                cpref[sum] = 1;
        }
        return ans;
    }
};

// O(1) Space O(n2) TIME - TLE
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0,n=nums.size();
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum += nums[j];
                if(sum == k) ans++;
            }
        }
        return ans;
    }
};

// O(N)space O(n2)TIME - TLE
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0,n=nums.size();
        vector<int>prefix(n+1);
        prefix[0] = 0;
        for(int i=1;i<=n;i++) prefix[i] = prefix[i-1] + nums[i-1];
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<=n;j++){
                if(prefix[j] - prefix[i] == k) ans++;
            }
        }
        return ans;
    }
};
