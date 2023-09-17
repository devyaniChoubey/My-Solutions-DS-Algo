
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