https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/?envType=company&envId=google&favoriteSlug=google-all

class Solution {
public:
    void computeLPSArray(string pat, vector<int>&lps){
        int len = 0, i = 1;
        lps[0] = 0;

        while(i < pat.size()){
            if(pat[i] == pat[len]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len != 0){
                    len = lps[len-1];
                }else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    int strStr(string haystack, string needle) {
        int i = 0, j = 0;
        int n = haystack.size();
        int m = needle.size();
        vector<int>lps(m);
        computeLPSArray(needle, lps);

        while(n-i >= m-j){
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }

            if(j == m){
                return i-j;
                j = lps[j-1];
            }else if(i < n && haystack[i] != needle[j]){
                if(j != 0){
                    j = lps[j-1];
                }else i++;
            }
        }

        return -1;
    }
};