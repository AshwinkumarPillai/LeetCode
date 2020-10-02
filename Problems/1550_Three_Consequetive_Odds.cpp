class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return false;
        int odds = 0;
        for(int i=0;i<n && odds<3;i++){
            odds = arr[i] % 2 ? odds+1 : 0;
        }
        return (odds == 3);
    }
};

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return false;
        for(int i=0;i+2<n;i++){
            if((arr[i] & 1) && (arr[i+1] & 1) && (arr[i+2] & 1)) return true;
        }
        return false;
    }
};
