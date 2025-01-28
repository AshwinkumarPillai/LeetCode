// Only iterate the set bit
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        
        while(n>0){
            ans++;
            n = n & (n-1);
        }
        return ans;
    }
};

// Right Shift
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        
        while(n>0){
            if((n & 1) > 0) ans++;
            n = n>>1;
        }
        return ans;
    }
};

// ------------------------- BUILTIN FUNCTIONS ---------------------------------------------------------------

// __builtin_popcount
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};

// Using bitset
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return bitset<32>(n).count();
    }
}