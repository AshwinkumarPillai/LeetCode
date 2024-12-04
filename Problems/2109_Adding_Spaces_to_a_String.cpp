// Two Pointer Approach
class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        int n = s.length(), index = 0, m = spaces.size();
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            if (index < m && spaces[index] == i)
            {
                index++;
                ans += " ";
            }
            ans += s[i];
        }
        return ans;
    }
};