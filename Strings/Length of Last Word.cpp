https://www.interviewbit.com/problems/length-of-last-word/
https://leetcode.com/problems/length-of-last-word/description/?envType=company&envId=google&favoriteSlug=google-three-months&status=TO_DO%2CATTEMPTED&difficulty=MEDIUM%2CEASY

//Solution 1

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int n = s.length() ;
        int lastIndex = n-1;

        while(lastIndex >= 0 && s[lastIndex] == ' '){
            lastIndex--;
        }


        while(lastIndex >= 0 && s[lastIndex] != ' '){
            ans++;
            lastIndex--;
        }

        return ans;
    }
};

//Solution 2


class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
        int ans;

        while(getline(ss,word, ' ')){
            if(word.size() == 0) continue;
            ans = word.size();
        }

        return ans;
    }
};


class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int n = s.length() ;
        int lastIndex = n-1;

        while(s[lastIndex] == ' '){
            lastIndex--;
        }


        for(int i=0;i <= lastIndex;i++){
            if(s[i] == ' ') ans = 0;
            else ans++;
        }

        return ans;
    }
};
