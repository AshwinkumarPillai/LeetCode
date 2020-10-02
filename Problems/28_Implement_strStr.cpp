class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        int n  = needle.length(),h = haystack.length(), index = 0;
        while(index < h-n+1){
            while(index < h-n+1 && haystack[index] != needle[0]) index++;
            int len = 0, i = 0;
            while(i<n && index<h && haystack[index] == needle[i]){
                i++;
                index++;
                len++;
            }
            if(len == n) return index - n;
            index = index - len + 1;
        }
        return -1;
    }
};
