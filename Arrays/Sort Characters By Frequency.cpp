
https://leetcode.com/problems/sort-characters-by-frequency/description/


class Solution {
public:
    string frequencySort(string s) {
        int cnt[128] = {};

        for(char &c:s) cnt[c]++;

        sort(s.begin() , s.end() , [&](char &a, char &b) {
           return (cnt[a] > cnt[b] || cnt[a] == cnt[b] && a < b);
        });

        return s;
    }
};





class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;

        for(char &c:s) freq[c]++;

        vector<pair<int,char>>freqVec;

        for(auto it:freq){
            freqVec.push_back({it.second, it.first});
        }

        sort(freqVec.begin() , freqVec.end() , [&](auto &it1, auto &it2){
            return (it1.first > it2.first);
        });

        string ans;

        for(auto& it:freqVec){
            ans.append(it.first, it.second);
        }

        return ans;
    }
};


class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char,int>freq;

        for(char &c:s) freq[c]++;

        vector<vector<char>>bucket(n+1);

        for(auto& [ch, f]: freq){
            bucket[f].push_back(ch);
        }

        string res;

        for(int i=n;i >= 1;i--){
            for(char &c:bucket[i]){
                res.append(i, c);
            }
        }

        return res;
    }
};