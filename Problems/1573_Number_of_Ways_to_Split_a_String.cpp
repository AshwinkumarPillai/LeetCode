class Solution {
public:
    int numWays(string s) {
        int ans = 0,ones = 0,n=s.length();
        long long mp = 1e9+7;
        ones = count(s.begin(),s.end(),'1');
        if(!ones) return ((((n-1)%mp)*((n-2)%mp))%mp / 2)%mp;
        if(ones % 3) return 0;
        ones /= 3;
        int count = 0;
        long long low = 0,high = 0;
        for(char x: s){
            if(x == '1')count++;
            if(count == ones) low++;
            else if(count == ones*2) high++;
        }
        return ((low%mp)*(high%mp)) % mp;
    }
};
