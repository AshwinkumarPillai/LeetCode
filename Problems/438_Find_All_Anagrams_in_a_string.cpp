class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = p.length();
        int n = s.length();
        vector<int>ans;
        if(m>n){
            return ans;
        }
        
        vector<int> alphabets(26);
        int count = 0;
        for(int i=0;i<m;i++){
            int index = (int)p[i] - 97;
            alphabets[index]++;
        }
        
        for(int i=0;i<m;i++){
            int index = (int)s[i] - 97;
            alphabets[index]--;
        }
        
        
        for(int x: alphabets){
            if(x!=0){
                count++;
            }
        }
        if(count == 0){
            ans.emplace_back(0);
        }
        
        
        for(int i=1,j=m;j<n;i++,j++){
            int back = (int)s[i-1] - 97;
            int front = (int)s[j] - 97;
            alphabets[back]++;    
            if(alphabets[back] == 0){
                count--;
            }else if(alphabets[back] == 1){
                count++;
            }
            alphabets[front]--;
            if(alphabets[front] == 0){
                count--;
            }else if(alphabets[front] == -1){
                count++;
            }
            if(count == 0){
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};