class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxval = INT_MIN;
        for(int x: candies) maxval = max(maxval,x);
        vector<bool>ans;
        for(int x: candies) { 
            if(x+extraCandies >= maxval) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};
