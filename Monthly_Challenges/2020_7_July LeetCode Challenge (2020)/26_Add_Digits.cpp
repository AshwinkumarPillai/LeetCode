// Math Soluiton - O(1)
class Solution {
public:
    int addDigits(int n) {
        if(n ==0) return 0;
        int ans = n % 9;
        if(!ans) return 9;
        return ans;
    }
};

// O(n) solution
class Solution {
public:
    int addDigits(int num) {
        if(num<10) return num;
        while(num>9){
            int ans = 0;
            while(num){
                ans += num %  10;
                num /= 10;
            }
            num = ans;
        }
        return num;
    }
};