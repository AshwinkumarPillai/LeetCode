// Bit Manip + Math
// x&x-1 == 0 : power of 2
// Even power of 2 when divided by 3 gives remainder 1 and odd power will give remainder 2
// Bcoz even power of 2 is 4 raise to k i.e. (3+1)^k %3 = 1
// and odd power of 2 is (2*4^k)mod 3 = (2*(3+1)^k)mod 3 = 2
class Solution
{
public:
    bool isPowerOfFour(int num)
    {
        return (num > 0) && !(num & (num - 1)) && (num % 3 == 1);
    }
};

// Bit manipulation - O(1) time and space
// (num & num-1) == 0 then it is a power of 2
// Now if it is a power of two then even bits(starting from 0 on the right) should be 1 - to be a power of 4 also
// so we can perfom & with 01010101010101010101010101010101 - 32 bit number with ones at even places from the right (first place is 0)
// This can be represented as aaaaaaaa in hexa decimal - so in cpp we write it as 0xaaaaaaaa - 0x = hexadecimal number
class Solution
{
public:
    bool isPowerOfFour(int num)
    {
        return (num > 0) && !(num & (num - 1)) && !(num & 0xaaaaaaaa);
    }
};

// O(1) - Time Space => if log2 of num is an even integer then it is a power of 4
// MATH
class Solution
{
public:
    bool isPowerOfFour(int num)
    {
        if (!num)
            return false;
        float p = log2(num);
        return (floor(p) == p) && !((int)p & 1);
    }
};

// O(1) - Time and Space - Precompute all 15 powers of 4 and chcek if it exists
class Solution
{
public:
    bool isPowerOfFour(int num)
    {
        vector<long long> pows;
        pows.push_back(1);
        for (int i = 1; i <= 15; i++)
            pows.push_back(pows.back() * 4);
        for (int x : pows)
            if (x == num)
                return true;
        return false;
    }
};

// Brute Force - O(logn) solution
class Solution
{
public:
    bool isPowerOfFour(int num)
    {
        if (num == 0)
            return false;
        while (!(num % 4))
            num /= 4;
        return (num == 1);
    }
};