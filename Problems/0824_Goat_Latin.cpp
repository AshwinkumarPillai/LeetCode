// Clean code
class Solution {
public:
    set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};  
    string toGoatLatin(string s) {
        string suffix = "a",ans="",token="";
        istringstream ss(s);
        while(ss>>token){
            if(vowels.count(token[0]) <= 0) token = token.substr(1) + token[0];
            ans += token + "ma" + suffix + " ";
            suffix += "a";
        }
        ans.pop_back();
        return ans;
    }
};

// With a helper function
class Solution {
public:
    string aend = "a";
    set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
    string performAction(string& word){
        if(vowels.count(word[0])){
            word += "ma";
            word += aend;
            aend += "a";
            return word;
        }
        string ans = "";
        int n = word.length();
        for(int i=1;i<n;i++){
            ans+= word[i];
        }
        ans += word[0];
        ans += "ma";
        ans += aend;
        aend += "a";
        return ans;
    }
    
    string toGoatLatin(string s) {
        int n = s.length(),i=0;
        string ans = "";
        while(i<n){
            string temp = "";
            while(i<n && s[i] != ' '){
                temp+= s[i++];
            }
            i++;
            ans += performAction(temp);
            if(i<n) ans += " ";
        }
        return ans;
    }
};
