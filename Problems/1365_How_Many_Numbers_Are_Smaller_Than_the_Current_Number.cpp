class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        map<int,pair<int,vector<int>>>m;
        for(int i=0;i<n;i++){
            int x = nums[i];
            if(m.find(x) != m.end()){
                m[x].first++;
                m[x].second.push_back(i);
            }else{
                m[x] = {1,{i}};
            }
        }
        vector<int>ans(n);
        int num = 0;
        for(auto p: m){
            vector<int>v = p.second.second;
            int count = p.second.first;
            for(auto x: v){
                ans[x] = num;
            }
            num+=count;
        }
        return ans;
    }
};
