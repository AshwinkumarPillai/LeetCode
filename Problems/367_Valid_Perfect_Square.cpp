class Solution {
public:
    bool isPerfectSquare(int num) {
        
        if(num == 0 || num == 1){
            return true;
        }
        
        long i = 1,maxsq = 1;
        while(maxsq < num){
            i++;
            maxsq = i*i;
        }
        
        
        if((i*i) == num){
            return true;
        }
        return false;
    }
};