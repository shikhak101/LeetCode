class Logger {
public:
    /** Initialize your data structure here. */
    map<string,int> m;
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        map<string,int>::iterator it = m.find(message);
        if(it == m.end()) {
            m.insert(make_pair(message,timestamp));
            return true;
        }
        if(timestamp - it->second >= 10){
            it->second = timestamp;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */