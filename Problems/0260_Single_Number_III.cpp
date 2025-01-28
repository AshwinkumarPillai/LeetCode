// Bit maipulation - O(1) Solution
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0,num1 = 0 ,num2 = 0;
        for(int x: nums) xr^=x;
        int setBit = 1;
        for(int i = 1;i<=31;i++){
            if(xr & setBit) break;
            setBit<<=1;
        }
        for(int x: nums){
            if((x&setBit) == setBit) num1 ^= x;
            else num2 ^= x;
        }
        return {num1,num2};
    }
};

// O(n) Space using map
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>m;
        for(int x:nums) m[x]++;
        cout<<xr;
        for(auto p:m) if(p.second == 1) ans.push_back(p.first);
        return ans;   
    }
};