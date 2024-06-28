https://leetcode.com/problems/longest-palindrome/

//Method 1

class Solution {
public:
    int longestPalindrome(string s) {
        int cnt[128] = {};

        for(char &c:s) cnt[c]++;

        bool oddcnt = false;

        int len = 0;

        for(int i=0;i < 128;i++){
            if(cnt[i] % 2 != 0) {
                oddcnt = true;
                len += (cnt[i]-1);
            }else len += (cnt[i]);
        }

        oddcnt && len++;

        return len;

    }
};

//Method 2 

class Solution {
public:
    int longestPalindrome(string s) {
        int oddCharCnt = 0;

        int freq[128];

        for(char &c:s){
            freq[c]++;
            if(freq[c] % 2 != 0) oddCharCnt++;
            else oddCharCnt--;
        }

        if(oddCharCnt > 0)return s.length() - oddCharCnt + 1;
        else return s.length();
    }
};



//Method 3
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char>seen;
        int res = 0;

        for(char &c:s){
            if(seen.count(c)){
                res += 2;
                seen.erase(c);
            }else seen.insert(c);
        }

        if(seen.size() > 0) return res + 1;
        else return res;
    }
};