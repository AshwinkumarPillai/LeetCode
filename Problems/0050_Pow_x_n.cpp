class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        double y = myPow(x,n/2);
        if(n&1) return (n < 0)?  1 / x * y * y : x*y*y;
        else return y*y;
    }
};