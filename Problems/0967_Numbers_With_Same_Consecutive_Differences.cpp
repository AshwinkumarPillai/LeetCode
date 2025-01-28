class Solution {
public:
    void dfs(vector<int>& ans,int num,int index,int n,int k){
        if(index == n){
            ans.push_back(num);
            return;
        }
        int lastIndex = num % 10;
        for(int i=0;i<10;i++){
            if(abs(i-lastIndex) == k) dfs(ans,num*10+i,index+1,n,k);
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        if(n == 1) return {0,1,2,3,4,5,6,7,8,9};
        vector<int>ans;
        for(int i=1;i<10;i++) dfs(ans,i,1,n,k);
        return ans;
    }
};
