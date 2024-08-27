
https://leetcode.com/problems/make-the-string-great/?envType=company&envId=google&favoriteSlug=google-six-months&status=TO_DO&difficulty=EASY%2CMEDIUM

class Solution {
public:
    string makeGood(string s) {
        vector<char>st;
        for(char &c:s){
            if(!st.empty() && ((isupper(c) && st.back() == tolower(c)) || (islower(c) && st.back() == toupper(c)))){
                st.pop_back();
            }else st.push_back(c);
        }

        string ans(st.begin() , st.end());

        return ans;
    }
};



class Solution {
public:
    string makeGood(string s) {
        vector<char>st;
        for(char &c:s){
            if(!st.empty() && abs(st.back() - c) == 32){
                st.pop_back();
            }else st.push_back(c);
        }

        string ans(st.begin() , st.end());

        return ans;
    }
};