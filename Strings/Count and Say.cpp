https://leetcode.com/problems/count-and-say/description/

class Solution {
public:
    string countIdx(string s){
        char c = s[0];
        int count = 1;

        string result = "";

        for(int i=1;i < s.length();i++){
            if(s[i] == c){
                count++;
            }else{
                result += to_string(count);
                result += c;

                c = s[i];
                count = 1;
            }
        }

        result += to_string(count);
        result += c;

        return result;
    }
    string countAndSay(int n) {
        string s = "1";

        for(int i=1;i < n;i++){
            s = countIdx(s);
        }

        return s;
    }
};