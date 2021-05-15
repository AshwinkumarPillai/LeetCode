class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>>ans;        
        for(int j=0;j<n;j++){
            vector<char>imv;
            for(int i=m-1;i>=0;i--){
                imv.push_back(box[i][j]);
            }
            ans.push_back(imv);
        }
        
        for(int j=0;j<m;j++){
            for(int i=n-2;i>=0;i--){
                if(ans[i][j] == '#'){
                    int k = i;
                    while(k+1 < n && ans[k+1][j] == '.') k++;
                    if(k != i){
                        ans[k][j] = '#';
                        ans[i][j] = '.';   
                    }
                }
            }
        }
        return ans;
    }
};