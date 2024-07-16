
https://leetcode.com/problems/snapshot-array/description/


class SnapshotArray {
public:
    int cur_snap = 0;
    unordered_map<int, map<int, int>>mp;
    SnapshotArray(int length) {
        
    }
    
    void set(int index, int val) {
        mp[index][cur_snap] = val;
    }
    
    int snap() {
        cur_snap++;
        return cur_snap - 1;
    }
    
    int get(int index, int snap_id) {
        auto it = mp[index].upper_bound(snap_id);

        if(it == mp[index].begin()) return 0;
        else{
            return prev(it)->second;
        }
    }
};





class SnapshotArray {
public:
    vector<vector<pair<int,int>>>vec;
    int len;
    int cur_snap = 0;
    SnapshotArray(int length) {
        len = length;
        vec.resize(len);
        for(int i=0;i < length;i++){
            vec[i].push_back({0,0});
        }
    }
    
    void set(int index, int val) {
        vec[index].push_back({cur_snap, val});
    }
    
    int snap() {
        cur_snap++;
        return cur_snap-1;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(vec[index].begin() , vec[index].end(), make_pair(snap_id, INT_MAX));

        if(it == vec[index].begin()) return 0;
        else return prev(it)->second;
    }
};
