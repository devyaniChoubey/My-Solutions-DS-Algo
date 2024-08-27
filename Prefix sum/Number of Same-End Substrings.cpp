https://leetcode.com/problems/number-of-same-end-substrings/

class Solution {
public:
    vector<int> sameEndSubstringCount(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int>count(26);
        vector<vector<int>>counts = {count};

        for(int i=0;i < n;i++){
            count[s[i] - 'a']++;
            counts.push_back(count);
        }

        vector<int>ans;
        
        for(int i=0;i < queries.size();i++){
            int left = queries[i][0];
            int right = queries[i][1];

            int cnt = 0;

            for(int j=0;j < 26;j++){
                int freq = counts[right+1][j] - counts[left][j];
                cnt += (freq)*(freq+1)/2;
            }

            ans.push_back(cnt);
        }

        return ans;

    }
};