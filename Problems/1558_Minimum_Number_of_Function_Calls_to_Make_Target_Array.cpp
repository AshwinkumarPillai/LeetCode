// Using cpp libs to use hardware operation benefits
class Solution {
public:
    int minOperations(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, [&](int s, int i) { return s + bitset<32>(i).count(); }) + log2(*max_element(nums.begin(), nums.end()));
    }
};

// Using bit check normally
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int op1 = 0,msb = 0;
        for(int i=0;i<=30;i++){
            for(int x: nums){
                if((x & (1<<i))){
                    op1++;
                    msb = i;
                }
            }
        }
        return op1 + msb;
    }
};
