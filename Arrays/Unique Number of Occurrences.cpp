https://leetcode.com/problems/unique-number-of-occurrences/description/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>freq;
        for(int num:arr) freq[num]++;

        unordered_set<int>freqSet;

        for(auto it:freq){
            if(freqSet.count(it.second)) return false;
            else freqSet.insert(it.second);
        }

        return freqSet.size() == freq.size();
    }
};