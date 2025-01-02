class Solution
{
public:
    bool isVowel(char x)
    {
        return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
    }

    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        vector<int> prefix;
        prefix.push_back(0);
        for (string word : words)
        {
            if (isVowel(word[0]) && isVowel(word[word.length() - 1]))
                prefix.push_back(prefix.back() + 1);
            else
                prefix.push_back(prefix.back());
        }

        vector<int> ans;

        for (vector<int> query : queries)
        {
            int l = query[0], r = query[1];
            ans.push_back(prefix[r + 1] - prefix[l]);
        }

        return ans;
    }
};