// Loop on all number
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


// Binary Search
class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 0, high = num;
        
        long mid;
        
        while(low<=high){
            mid = low + (high-low)/2;
            if(mid * mid == num) return true;
            if(mid * mid > num) high = mid - 1;
            else low = mid+1;
        }
        return false;
    }
};