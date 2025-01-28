// one pass
class Solution {
public:
    int getNum(string& s,int& i,int n){
        string ans = "";
        while(i<n){
            if(s[i] == '.'){
                i++;
                return stoi(ans);
            }
            ans += s[i];
            i++;
        }
        if(ans != "") return stoi(ans);
        return 0;
    }
    
    int compareVersion(string version1, string version2) {
        int as = version1.size(),bs = version2.size();
        int n = max(as,bs);
        int i=0,j=0,val1,val2;
        while(i< as || j< bs){
            val1 = getNum(version1,i,as);
            val2 = getNum(version2,j,bs);
            if(val1 != val2) return (val1 > val2) ? 1 : -1;
        }
        return 0;
    }
};

// two Pass
// array - shorter code
class Solution {
public:
    
    vector<int> getNums(string& s){
        vector<int>ans;
        string temp = "";
        for(char x: s){
            if(x == '.'){
                ans.push_back(stoi(temp));
                temp = "";
            }else{
                temp += x;
            }
        }
        if(temp != "") ans.push_back(stoi(temp));
        return ans;
    }
    
    int compareVersion(string version1, string version2) {
        vector<int>a = getNums(version1);
        vector<int>b = getNums(version2);
        int as= a.size(),bs = b.size();
        int n = max(as,bs);
        int val1,val2;
        for(int i=0;i<n;i++){
            val1 = (i<as) ? a[i] : 0;
            val2 = (i<bs) ? b[i] : 0;
            if(val1 != val2) return (val1 > val2) ? 1 :-1;
        }
        return 0;
    }
};


// array - 2
class Solution {
public:
    
    vector<int> getNums(string& s){
        vector<int>ans;
        string temp = "";
        for(char x: s){
            if(x == '.'){
                ans.push_back(stoi(temp));
                temp = "";
            }else{
                temp += x;
            }
        }
        if(temp != "") ans.push_back(stoi(temp));
        return ans;
    }
    
    void setup(vector<int>&a,vector<int>&b){
        int n = a.size(),m=b.size();
        if(n == m) return;
        int val = abs(n-m);
        if(m<n)
            while(val--) b.push_back(0);
        else
            while(val--) a.push_back(0);
    }
    
    int check(vector<int>& a,vector<int>& b){
        int n  = a.size();
        for(int i=0;i<n;i++){
            if(a[i] < b[i]) return -1;
            else if(a[i] > b[i]) return 1;
        }
        return 0;
    }
    
    int compareVersion(string version1, string version2) {
        vector<int>a = getNums(version1);
        vector<int>b = getNums(version2);
        setup(a,b);
        return check(a,b);
    }
};
