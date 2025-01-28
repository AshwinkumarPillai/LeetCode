// Binomial coeffecient
// nCr / nCr-1 = (n-r+1) / r
// so, nCr = nCr-1 * (n-r+1/r)

class Solution {
public:
    vector<int> getRow(int k) {
        vector<int>ans = {1};
        for(int i=1;i<=k;i++) ans.push_back(int(ans.back()*(long long)(k-i+1)/i));        
        return ans;
    }
};


// Genius method
// if we want the 3th row(0-index) i.e. with 4 elements - [1,3,3,1]
// let ans array be [1,1,1,1]
// the using loops we will generate all values
// i=1 [1,2,1,1]
// i=2 [1,3,3,1]
// i=3 is not less than 3 so return ans
// for 4 it would be
// [1,1,1,1,1] -> [1,2,1,1,1] -> [1,3,3,1,1] -> [1,4,6,4,1]

class Solution {
public:
    vector<int> getRow(int k) {
        vector<int>ans(k+1,1);
        
        for(int i=1;i<k;i++){
            for(int j=i;j>0;j--){
                ans[j] += ans[j-1];
            }
        }        
        return ans;
    }
};

// Generate Pascals Triangle
class Solution {
public:
    vector<int> getRow(int k) {
        vector<vector<int>>p(k+1,vector<int>(k+1));
        vector<int>ans;
        
        for(int i=0;i<k+1;i++){
            for(int j=0;j<=i;j++){
                if(j==0||j==i){
                    p[i][j] = 1;
                }
                else{
                    p[i][j] = p[i-1][j] + p[i-1][j-1];
                }
            }
        }
        
        for(int x: p[k]){
            ans.emplace_back(x);
        }
        return ans;
    }
};