https://leetcode.com/problems/word-subsets/?envType=daily-question&envId=2025-01-10

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>freq(26, 0);

        for(int i=0;i < words2.size();i++){
            vector<int>temp(26, 0);

            for(char &c:words2[i]){
                temp[c-'a']++;
                freq[c-'a'] = max(freq[c-'a'] , temp[c-'a']);
            }
        }

        vector<string>ans;

        for(int i=0;i < words1.size();i++){
            vector<int>temp(26, 0);

            for(char &c:words1[i]){
                temp[c-'a']++;
            }

            for(int j=0;j < 26;j++){
                if(temp[j] < freq[j]) break;
                if(j == 25) ans.push_back(words1[i]);
            }
        }

        return ans;
    }
};