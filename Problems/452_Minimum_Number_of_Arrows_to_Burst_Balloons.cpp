// Sort the segments by the end
// put an arrow at the end of the 1-st segment
// from the 2-nd segment, we check whether the current arrow pass through the current segment, if not add an arrow, put it at the end of the current segment

class Solution {
public:

    static bool compare(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        int ans = 0;
        sort(points.begin(), points.end(), compare);
        int arrow = -1;
        // for(vector<int> point: points){
        for(int i = 0; i < points.size(); i++){
            if(ans == 0 || points[i][0] > arrow){
                ans++;
                arrow = points[i][1];
            }
        }
        return ans;
    }
};