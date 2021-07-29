class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        n = target[target.size() - 1];
        vector<string>ans;
        int index = 0;
        for(int i=1;i<=n;i++){
            ans.push_back("Push");
            if(target[index] != i){
                ans.push_back("Pop");
            }
            else index++;
        }
        return ans;
    }
};
