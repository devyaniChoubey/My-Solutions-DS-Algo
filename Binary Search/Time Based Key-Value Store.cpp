https://leetcode.com/problems/time-based-key-value-store/description/

class TimeMap {
public:
    unordered_map<string, map<int, string>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = mp[key].upper_bound(timestamp);
        if(it == mp[key].begin()) return "";
        else{
            it--;
            return it->second;
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */