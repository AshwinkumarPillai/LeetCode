class Solution {
public:
    map<string,string>m;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string s = "http://tinyurl.com/";
        string hashval = to_string(rand()%10000007) + to_string(time(0));
        string url = s + hashval;
        m[url] = longUrl;
        return url;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};

