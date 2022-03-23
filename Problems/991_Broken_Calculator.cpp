class Solution {
public:
    
    // Start from target and go backwards
    // if target is even divide by 2 if it is odd add 1
    // do this till target is greater than the startVal
    // then increment target till we reach startVal => for this we do (startval - target)
    
    int brokenCalc(int startValue, int target) {
        int ans = 0;
        while(target > startValue){
            target = target % 2 == 0 ? target / 2: target + 1;
            ans++;
        }
        return ans + (startValue - target);
    }
};
