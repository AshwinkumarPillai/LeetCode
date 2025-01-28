
// Method 1: Time - O(n) | Space - O(n)

class Solution {
public:
    
    pair<int,int> getCount(vector<char>& s, int i, int n){
        int count = 1;
        char x = s[i++];
        while(i<n){
            if(s[i] == x) i++,count++;
            else break;
        }
        return {i,count};
    }
    
    int compress(vector<char>& chars) {
        string ans = "";
        int n = chars.size();
        int i = 0;
        while(i<n){
            pair<int,int>p = getCount(chars, i, n);
            int count = p.second;
            if(count == 1) ans += chars[i];
            else ans += chars[i] + to_string(count);
            i = p.first;
        }
        chars.clear();
        for(char x: ans) chars.push_back(x);
        return ans.length();
    }
}; 

// Method 2: Inplace compression - without extra space
class Solution {
public:
    
    pair<int,int> getCount(vector<char>& s, int i, int n){
        int count = 1;
        char x = s[i++];
        while(i<n){
            if(s[i] == x) i++,count++;
            else break;
        }
        return {i,count};
    }
    
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0, j = 0; // i = the index where we want to fill | j = to count occurance and next characters
        while(i<n && j < n){
            pair<int,int>p = getCount(chars, j, n);
            int count = p.second;
            chars[i] = chars[j];
            if(count>1){
                if(count<10) chars[++i] = count + '0';
                else{
                    string s = to_string(count);
                    for(char x: s){
                        chars[++i] = x;
                    }
                }
            }
            j = p.first;
            i++;
        }
        return i;
    }
};
