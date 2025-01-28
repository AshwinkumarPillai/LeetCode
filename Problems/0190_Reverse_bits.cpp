// Set 31-ith bit
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans = 0;
        for (int i = 0; i <= 31; i++)
            ans += (n & (1 << i)) ? 1 << (31 - i) : 0;
        return ans;
    }
};

// Bitset Swap
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        bitset<32> b = {n};
        int left = 0, right = 31;
        while (left < right)
        {
            bool t = b[left];
            b[left++] = b[right];
            b[right--] = t;
        }
        return b.to_ulong();
    }
};