class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        int wordIndex = 1, currIndex = 0, n = sentence.size();
        int searchIndex = 0, sn = searchWord.size();

        while (currIndex < n)
        {
            if (searchWord[searchIndex] == sentence[currIndex])
            {
                if (++searchIndex == sn)
                    return wordIndex;
            }
            else
            {
                searchIndex = 0;
                wordIndex++;
                while (currIndex < n && sentence[currIndex] != ' ')
                    currIndex++;
            }
            currIndex++;
        }

        return -1;
    }
};