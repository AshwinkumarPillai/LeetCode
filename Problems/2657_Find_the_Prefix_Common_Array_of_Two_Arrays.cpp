// 0ms solution - O(n) TIME, O(1) space
class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        vector<int> freq(A.size() + 1);
        vector<int> ans(A.size());
        int sum = 0;
        for (int i = 0; i < A.size(); i++)
        {
            if (++freq[A[i]] == 2)
                sum++;
            if (++freq[B[i]] == 2)
                sum++;
            ans[i] = sum;
        }
        return ans;
    }
};

// 4ms solution - O(n) TIME, O(1) space
class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        vector<int> freq(A.size() + 1);
        vector<int> ans(A.size());
        for (int i = 0; i < A.size(); i++)
        {
            if (i > 0)
                ans[i] = ans[i - 1];
            if (++freq[A[i]] == 2)
                ans[i]++;
            if (++freq[B[i]] == 2)
                ans[i]++;
        }
        return ans;
    }
};