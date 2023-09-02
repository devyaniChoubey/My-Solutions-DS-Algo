https://leetcode.com/problems/rotate-string/description/

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;

        for(int i=0;i < s.length();i++){
            char c = s[0];
            s.erase(0, 1);
            s.push_back(c);

            if(s == goal) return true;
        }

        return false;
    }
};




class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;


        if((s + s).find(goal) != string::npos) return true;
        else return false; 

    }
};