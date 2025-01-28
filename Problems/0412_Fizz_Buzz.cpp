// Universal solution
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        map<int,string>m;
        m[3] = "Fizz";m[5] = "Buzz";
        vector<string>ans;
        for(int i=1;i<=n;i++){
            string out = "";
            for(auto p: m){
                if(i%p.first == 0) out+= p.second;
            }
            if(out == "") out+= to_string(i);
            ans.push_back(out);
        }
        return ans;
    }
};

// Simple loop
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        if(n == 1) return {"1"};
        if(n == 2) return {"1","2"};
        if(n == 3) return {"1","2","Fizz"};
        vector<string>ans;
        string t = "Fizz",f="Buzz",tf="FizzBuzz";
        ans.push_back("1");
        ans.push_back("2");
        ans.push_back("Fizz");
        for(int i=4;i<=n;i++){
            if((i%3 == 0) && (i%5 == 0)) ans.push_back(tf);
            else if(i%3 == 0) ans.push_back(t);
            else if(i%5 == 0) ans.push_back(f);
            else ans.push_back(to_string(i));
        }
        return ans;
    }
};
