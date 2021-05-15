class Solution:
    def sortSentence(self, s: str) -> str:
        words = s.split()
        orw = []
        for i in range(len(words)):
            orw.append(str(i))
        for word in words:
            index = int(word[-1]) - 1
            val = word[:len(word)-1]
            orw[index] = val
        ans = ""
        for word in orw:
            ans = ans + word + " "
        return ans[:len(ans)-1]