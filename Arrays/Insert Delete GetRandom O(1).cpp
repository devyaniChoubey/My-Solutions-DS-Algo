https://leetcode.com/problems/insert-delete-getrandom-o1/?envType=company&envId=google&favoriteSlug=google-six-months&difficulty=EASY%2CMEDIUM&status=TO_DO

class RandomizedSet {
public:
    unordered_map<int,int>mp;
    vector<int>arr;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        arr.push_back(val);
        mp[val] = arr.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        int idx = mp[val];
        int lastVal = arr.back();

        arr[idx] = lastVal;
        mp[lastVal] = idx;


        arr.pop_back();
        mp.erase(val);
        
        return true;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};
