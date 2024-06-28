https://leetcode.com/problems/car-pooling/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>t(1001, 0);

        for(auto it:trips){
            int passenger = it[0], from = it[1], to = it[2];

            t[from] += passenger;
            t[to] -= passenger;
        }

        for(int i=0;i < 1001;i++){
            if(i > 0) t[i] += t[i-1];
            if(t[i] > capacity) return false;
        }

        return true;
    }
};