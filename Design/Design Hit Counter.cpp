
https://leetcode.com/problems/design-hit-counter/description/


class HitCounter {
public:
    map<int,int>hits;
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        for(auto it:hits){
            if(timestamp-it.first >= 300){
               hits.erase(it.first);
            }
        }
        hits[timestamp]++;
    }
    
    int getHits(int timestamp) {
        int ans = 0;
        for(auto it:hits){
            if(timestamp-it.first < 300){
               ans += it.second;
            }else hits.erase(it.first);
        }
        return ans;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */



//Method 2
class HitCounter {
public:
    vector<int>hits;
    vector<int>times;
    HitCounter() {
        hits.resize(300, 0);
        times.resize(300, 0);
    }
    
    void hit(int timestamp) {
        int index = timestamp%300;

        if(times[index] != timestamp){
            times[index] = timestamp;
            hits[index] = 1;
        }else hits[index]++;
    }
    
    int getHits(int timestamp) {
        int ans = 0;
        
        for(int i=0;i < 300;i++){
            if(timestamp-times[i] < 300){
               ans += hits[i];
            }
        }

        return ans;
    }
};


class HitCounter {
public:
    queue<int>q;
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        q.push(timestamp);
    }
    
    int getHits(int timestamp) {
        while(!q.empty()){
            if(timestamp - q.front() >= 300) q.pop();
            else break;
        }

        return q.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */