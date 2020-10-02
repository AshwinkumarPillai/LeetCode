class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int& num: nums){
            int count = 0;
            while(num){
                num/=10;
                count++;
            }
            if(!(count&1)) ans++;
        }
        return ans;
    }
};
