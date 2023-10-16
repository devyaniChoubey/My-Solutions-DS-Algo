https://leetcode.com/problems/bulls-and-cows/description/

https://leetcode.com/problems/bulls-and-cows/editorial/
//Two Pass

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int>freq;

        for(char &c:secret) freq[c]++;
        int bullCnt = 0, cowsCnt = 0;

        for(int i=0;i < guess.length();i++){
            char ch = guess[i];
            if(freq .find(ch) != freq.end()){
                if(secret[i] == ch){
                    bullCnt++;

                    if(freq[ch] <= 0) cowsCnt--;
                }else{
                    if(freq[ch] > 0) cowsCnt++;
                }
                freq[ch]--;
            }
        }

        return to_string(bullCnt) + "A" + to_string(cowsCnt) + "B";
    }
};


//One Pass
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int>freq;
        int bulls = 0, cows = 0;

        for(int i=0;i < secret.length();i++){
            char s = secret[i];
            char g = guess[i];
            if(s == g){
                bulls++;
            }else{
                if(freq[s] < 0) cows++;
                if(freq[g] > 0) cows++;

                freq[s]++;
                freq[g]--;
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};