class Solution {
public:
    
    void stripString(string& s, string& d,int c){
        for(char x: d){
            int cnt = c;
            for(char &y: s){
                if(cnt == 0) break;
                if(x == y) {
                    cnt--;
                    y = '\0';
                }
            }
        }
    }
    
    int countAndRemove(string& s, char& x, string& d){
        int count = 0;
        for(char y: s) if(y == x) count++;
        stripString(s,d,count);
        return count;
    }
    
    string originalDigits(string s) {
        vector<char>vals = {'z','w','u','x','g','o','h','f','s','i'};
        vector<string>dig = {"zero","two","four","six","eight","one","three","five","seven","nine"};
        vector<string>intval = {"0","2","4","6","8","1","3","5","7","9"};
        string ans = "";
        for(int i=0;i<10;i++){
            // cout<<"\n"<<i<<":\nString: "<<s<<"\n";
            int cnt = countAndRemove(s,vals[i],dig[i]);
            // cout<<"COUNT: "<<cnt<<" String: "<<s<<" ANS: ";
            while(cnt>0){
                ans += intval[i];
                cnt--;
            }
            // cout<<ans<<"\n";
            if(s == "") break;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};


// {z}ero one t{w}o three fo{u}r five si{x} seven ei{g}ht nine
// {o}ne t{h}ree {f}ive {s}even nine
// nine
