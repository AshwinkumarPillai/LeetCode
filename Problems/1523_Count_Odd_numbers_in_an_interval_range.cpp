class Solution {
public:
    int countOdds(int low, int high) {
        // int x = (high - low )/ 2;
        // if(((high & 1 )== 0 ) && ((low & 1) == 0)) return x;
        // return x + 1;
        return (high + 1) / 2 - (low/2);
    }
};
