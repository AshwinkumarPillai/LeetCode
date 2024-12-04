// Two Pointer Approach

class Solution
{
public:
    bool canMakeSubsequence(string str1, string str2)
    {
        int index1 = 0, index2 = 0;
        int n1 = str1.length(), n2 = str2.length();

        while (index2 < n2 && index1 < n1)
        {
            if (str1[index1] == str2[index2] || ((str1[index1] - 'a' + 1) % 26) == (str2[index2] - 'a'))
            {
                index2++;
            }
            index1++;
        }

        return index2 == n2;
    }
};