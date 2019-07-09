class Solution {
public:
    hash<string> hashmap;
    map<string,string> strmap;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string str = to_string(hashmap(longUrl));
        strmap[str] = longUrl;
        string result = "http://tinyurl.com/"+str;
        return result;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string str = "http://tinyurl.com/";
        string result = strmap[shortUrl.substr(str.size())];
        return result;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));