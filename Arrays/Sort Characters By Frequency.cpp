
https://leetcode.com/problems/sort-characters-by-frequency/description/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int>count_map;

        for(char c:s){
            count_map[c]++;
        }

        int n = s.length();

        vector<char>bucket[n+1];



        for(auto it:count_map){
            bucket[it.second].push_back(it.first);
        }

        string res;


        for(int i=n;i >= 0;i--){
            for(int j=0;j < bucket[i].size();j++) res.append(i, bucket[i][j]);
        }

        return res;
        
    }
};