https://leetcode.com/problems/logger-rate-limiter/description/


//Method 1

class Logger {
public:
    unordered_map<string, int>lasttimestamp;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(lasttimestamp.find(message) == lasttimestamp.end()){
            lasttimestamp[message] = timestamp;
            return true;
        }else{
            if(timestamp - lasttimestamp[message] >= 10){
                lasttimestamp[message] = timestamp;
                return true;
            }else return false;
        }


    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */



//Method 2
class Logger {
public:
    queue<pair<string, int>>msgQueue;
    unordered_set<string>msgSet;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        while(!msgQueue.empty()){
            auto it = msgQueue.front();
            if(timestamp - it.second >= 10){
                msgQueue.pop();
                msgSet.erase(it.first);
            }else break;
        }

        if(!msgSet.count(message)){
            msgSet.insert(message);
            msgQueue.push({message, timestamp});
            return true;
        }else{
            return false;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */