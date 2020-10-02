class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0, j = 0;
        int count = 0;
        unordered_set<char> ss;
        while (j < s.length())
        {
            if (ss.find(s[j]) == ss.end())
            {
                ss.insert(s[j]);
                j++;
                int n = ss.size();
                count = max(n, count);
            }
            else
            {
                ss.erase(ss.find(s[i]));
                i++;
            }
        }
        return count;
    }
};