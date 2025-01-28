// Sol 1
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0,j= s.size() -1;
        
        while(i<=j){
            swap(s[i++], s[j--]);
        }
    }
};


// Sol 2
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for(int i=0;i<n/2;i++){
            int temp = s[n-i-1];
            s[n-i-1] = s[i];
            s[i] = temp;
        }
    }
};