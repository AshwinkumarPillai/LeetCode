// Merging list on the go (OFFICIAL)
class Solution {
public:    
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& block) {
        vector<vector<int>>ans;
        int start = block[0],end = block[1];
        int i=0,n=arr.size();
        while(i<n && arr[i][0] < start) ans.push_back(arr[i++]);
        vector<int>interval;
        if(!ans.size() || ans.back()[1] < start) ans.push_back(block);
        else{
            interval = ans.back();
            ans.pop_back();
            interval[1] = max(interval[1],end);
            ans.push_back(interval);
        }
        while(i<n){
            interval = arr[i++];
            start = interval[0];end=interval[1];
            if(ans.back()[1] < start) ans.push_back(interval);
            else{
                interval = ans.back();
                ans.pop_back();
                interval[1] = max(interval[1],end);
                ans.push_back(interval);
            }
        }
        return ans;
    }
};


