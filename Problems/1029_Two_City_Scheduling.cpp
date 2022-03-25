class Solution {
public:
    
    static bool compare(vector<int>& a, vector<int>& b){
        return (a[0] - a[1]) < (b[0] - b[1]);
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), compare);
        int i = 0, n = costs.size(), ans = 0;
   
        while(i<n/2){
            ans += costs[i][0];
            i++;
        }
        while(i<n){
            ans += costs[i][1];
            i++;
        }
        return ans;
    }
};