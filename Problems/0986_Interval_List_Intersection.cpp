class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int n = A.size();
        int m = B.size();
        int i=0,j=0;
        while(i<n && j<m){
            vector<int> a = A[i];
            vector<int> b = B[j];
            vector<int> t(2);
            t[0] = max(a[0],b[0]);
            t[1] = min(a[1],b[1]);
            if(t[0] <= t[1]){
                ans.emplace_back(t);
            }
            if(b[1] < a[1]){
                j++;
            }else{
                i++;
            }
        }
        return ans;
    }
};