// O(nlogn) - using map lower bound
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int>ans;
        map<int,int>m;
        int n = intervals.size();
        for(int i = 0;i<n;i++) m[intervals[i][0]] = i;
        
        for(int i = 0;i<n;i++){
            auto it = m.lower_bound(intervals[i][1]);
            if(it == m.end()) ans.push_back(-1);
            else ans.push_back(it->second);
        }
        return ans;
    }
};

// Without using lower bound
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int>ans;
        map<int,int>m;
        int n = intervals.size(),maxstart = INT_MIN;
        for(int i = 0;i<n;i++){
            int x = intervals[i][0];
            m[x] = i;
            maxstart = max(maxstart,x);
        }

        for(auto x: intervals){
            int start = x[1];
            int flag = 0;
            for(int i = start;i<=maxstart;i++){
                if(m.count(i)){
                    ans.push_back(m[i]);
                    flag = 1;
                    break;
                }
            }
            if(!flag) ans.push_back(-1);
        }
        return ans;
    }
};
