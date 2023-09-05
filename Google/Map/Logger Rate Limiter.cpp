https://leetcode.com/problems/logger-rate-limiter/description/

class Logger {
public:
    unordered_map<string, int>mp;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(mp.find(message) == mp.end() || mp[message] <= timestamp-10){
            mp[message] = timestamp;
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






class Logger {
public:
    unordered_map<string, int>mpNew;
    unordered_map<string, int>mpOld;
    int timeNew = INT_MIN;
    Logger() {
         
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(timestamp >= timeNew + 20){
            mpNew.clear();
            mpOld.clear();
            timeNew = timestamp;
        }else if(timestamp >= timeNew + 10){
            swap(mpNew, mpOld);
            mpNew.clear();
            timeNew = timestamp;
        }

        if(mpNew.find(message) != mpNew.end()) return false;

        if(mpOld.find(message) != mpOld.end() && timestamp < mpOld[message] + 10) return false;

        mpNew[message] = timestamp;

        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */