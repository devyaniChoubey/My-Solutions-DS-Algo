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



class Solution {
public:
    string countingSort(string &s){
        string t;
        int counter[26] = {};

        for(char &c:s) counter[c-'a']++;

        for(int i=0;i < 26;i++){
            t += string(counter[i] , i+'a');
        }

        return t;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;

        for(string &str:strs){
            string s = str;
            s = countingSort(s);
            mp[s].push_back(str);
        }


        vector<vector<string>>anagrams;

        for(auto &it:mp){
            anagrams.push_back(it.second);
        }

        return anagrams;
    }
};