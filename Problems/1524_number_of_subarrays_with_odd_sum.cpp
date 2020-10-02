class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long even = 1,odd = 0, sum = 0,ans = 0;
        for(int x: arr){
            sum += x;
            if(sum & 1){
                ans += even;
                odd ++;
            }else{
                ans += odd;
                even++;
            }
        }
        return ans % 1000000007;
    }
};
