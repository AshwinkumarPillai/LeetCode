class Solution {
public:
    bool checkHexa(char x){
        return ((x>='a' && x<='f') || (x>='A' && x<='F') || (x>='0' && x<='9'));
    }
    bool checkCount(string& s,int v){
        if(v == 0){
            int c = 3;
            for(int i=0;i<(int)s.length();i++){
                if(s[i] == '.' && (--c < 0)) return false;
            }
        }else{
            int c = 7;
            for(int i=0;i<(int)s.length();i++){
                if(s[i] == ':' && (--c < 0)) return false;
            }
        }
        return true;
    }
    bool checkIPV4(string& address){
        if(!checkCount(address,0)) return false;
        char* ip = new char[address.length() + 1];
        strcpy(ip, address.c_str());
        char deli[] = ".";
        char *word = strtok(ip,deli);
        int count = 0;
        while(word){
            count++;
            string s = word;
            if(s.size() == 0 || (s.size()  > 1 && s[0]== '0') || s.length() > 3){
                return false;
            }
            for(char x: s){
                if(x<'0' || x>'9'){
                    return false;
                }
            }
            if(stoi(s) <0 || stoi(s)>255) return false;
            word = strtok(NULL,deli);
        }
        return (count == 4);
    }
    bool checkIPV6(string& address){
        if(!checkCount(address,1)) return false;
        char* ip = new char[address.length() + 1];
        strcpy(ip, address.c_str());
        char deli[] = ":";
        char *word = strtok(ip,deli);
        int count = 0;
        while(word){
            count++;
            string s = word;
            // cout<<"S: "<<s<<"\n";
            if(s.size()>4) return false;
            for(char x: s){
                if(!checkHexa(x)) return false;
            }
            word = strtok(NULL,deli);
        }
        return (count == 8);
    }
    string validIPAddress(string IP) {
        int v4 = false;
        int n = IP.size();
        if(n==0 || IP[n-1] == '.' || IP[n-1] == ':') return "Neither";
        for(int i=0;i<4;i++){
            if(IP[i] == '.'){
                v4  = true;
                break;
            }
        }
        int ans;
        if(v4) ans = checkIPV4(IP);
        else ans = checkIPV6(IP);
        if(!ans) return "Neither";
        else if(v4) return "IPv4";
        return "IPv6";
    }
};