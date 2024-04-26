https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>hash;

        vector<vector<string>>ans;

        for(auto &st:strs){
            string orgStr = st;
            sort(st.begin(), st.end());
            hash[st].push_back(orgStr);
        }

        for(auto it:hash){
            ans.push_back(it.second);
        }

        return ans;
    }
};