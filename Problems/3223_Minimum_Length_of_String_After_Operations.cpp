class Solution
{
public:
    int minimumLength(string s)
    {
        vector<int> freq(26);
        int deleted = 0;
        for (char x : s)
            freq[x - 'a']++;
        for (int f : freq)
        {
            if (f == 0)
                continue;
            if (f % 2 == 0)
                deleted += f - 2; // even = keep two in the string
            else
                deleted += f - 1; // odd = only keep one
        }

        return s.size() - deleted;
    }
};