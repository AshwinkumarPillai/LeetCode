class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> alphabets(26);
        int m = s1.length();
        int n = s2.length();

        if (m > n)
        {
            return false;
        }

        for (int i = 0; i < m; i++)
        {
            alphabets[s1[i] - 'a']++;
            alphabets[s2[i] - 'a']--;
        }

        int count = 0;

        for (int x : alphabets)
        {
            if (x != 0)
            {
                count++;
            }
        }

        if (count == 0)
        {
            return true;
        }

        for (int i = 1, j = m; j < n; i++, j++)
        {
            alphabets[s2[i - 1] - 'a']++;
            if (alphabets[s2[i - 1] - 'a'] == 0)
            {
                count--;
            }
            else if (alphabets[s2[i - 1] - 'a'] == 1)
            {
                count++;
            }
            alphabets[s2[j] - 'a']--;
            if (alphabets[s2[j] - 'a'] == 0)
            {
                count--;
            }
            else if (alphabets[s2[j] - 'a'] == -1)
            {
                count++;
            }

            if (count == 0)
            {
                return true;
            }
        }
        cout << count;
        if (count != 0)
        {
            return false;
        }
        return true;
    }
};