https://leetcode.com/problems/find-common-characters/

//Most optimised
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();

        int counter[26] = {};

        for(char &ch:words[0]) counter[ch-'a']++;

        for(int i=1;i < n;i++){
            int counter1[26] = {};
            for(char &ch:words[i]){
                counter1[ch-'a']++;
            }

            for(int j=0;j < 26;j++){
                counter[j] = min(counter1[j], counter[j]);
            }
        }

        vector<string>ans;

        for(int i=0;i < 26;i++){
            for(int k=0;k < counter[i];k++){
                ans.push_back(string(1, i+'a'));
            }
        }

        return ans;

        
    }
};

//Less Optimised

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();


        vector<vector<int>>freq(n, vector<int>(26, 0));

        for(int i=0;i < n;i++){
            for(char &ch:words[i]){
                freq[i][ch-'a']++;
            }
        }

        vector<string>ans;

        for(int i=0;i < 26;i++){
            int mini = 1e9;
            for(int j=0;j < n;j++){
               mini = min(mini, freq[j][i]);
            }

            for(int k=0;k < mini;k++){
                ans.push_back(string(1, i+'a'));
            }
        }

        return ans;

        
    }
};