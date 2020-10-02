class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        int n = nums.size();
        set<int>s;
        for(int x: nums) if(++m[x] > (n/3)) s.insert(x);
        vector<int>ans(s.begin(),s.end());
        return ans;
    }
};
