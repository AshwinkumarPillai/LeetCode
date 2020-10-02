class Solution {
public:
    static bool compare(vector<int>&a,vector<int>&b){
        return (a[0] - a[1]) < (b[0] - b[1]);
    }
    int twoCitySchedCost(vector<vector<int>>& c) {
        sort(c.begin(),c.end(),compare);
        int n = c.size();
        int i;
        int ans = 0;
        for(i=0;i<n/2;i++){
            ans+=c[i][0];
        }
        while(i<n){
            ans+=c[i++][1];
        }
        
        return ans;
    }
};