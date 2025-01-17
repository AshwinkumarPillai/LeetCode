// FINAL XOR should be 0
class Solution
{
public:
    bool doesValidArrayExist(vector<int> &derived)
    {
        int ans = 0;
        for (int &x : derived)
            ans ^= x;
        return ans == 0;
    }
};

// FINAL SUM SHOULD BE EVEN
class Solution
{
public:
    bool doesValidArrayExist(vector<int> &derived)
    {
        int sum = 0;
        for (int &x : derived)
            sum += x;
        return !(sum & 1);
    }
};