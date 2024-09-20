https://leetcode.com/problems/uncommon-words-from-two-sentences/submissions/1392861261/?envType=daily-question&envId=2024-09-17

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream ss(s1 + " " + s2);
        unordered_map<string,int>seen;

        string temp;

        while(ss >> temp){
            seen[temp]++;
        }

        vector<string>ans;

        for(auto it:seen) if(it.second == 1)ans.push_back(it.first);

        return ans;
    }
};