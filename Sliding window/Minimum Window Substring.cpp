https://leetcode.com/problems/minimum-window-substring/description/

class Solution {
public:
    string minWindow(string str, string pat) {
        int hash_pat[256] = {0};
        int hash_str[256] = {0};

        for(char c:pat){
            hash_pat[c]++;
        }

        int n = str.length();
        int p = pat.length();

        int left = 0, right = 0, len = INT_MAX, startInd = -1, cnt = 0;

        while(right < n){
            hash_str[str[right]]++;

            if(hash_str[str[right]] <= hash_pat[str[right]]) cnt++;

            if(cnt == p){
                while(hash_str[str[left]] > hash_pat[str[left]]){
                    hash_str[str[left]]--;
                    left++;
                }

                if(len > right - left + 1){
                    len = right - left + 1;
                    startInd = left;
                }
            }

            right++;
        }

        if(startInd == -1) return "";
        else return str.substr(startInd, len);
    }
};