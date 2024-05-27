https://leetcode.com/problems/destination-city/

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, bool>hasOutgoing;

        for(auto it:paths){
            hasOutgoing[it[0]] = true;
        }

        for(auto it:paths){
            if(hasOutgoing[it[1]] == false) return it[1];
        }

        return "";
    }
};