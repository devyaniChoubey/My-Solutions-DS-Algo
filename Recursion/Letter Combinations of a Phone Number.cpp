https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    void solve(int ind, string path, string digits, unordered_map<char, string>&letters,vector<string>&combinations){

        if(ind >= digits.size()){
            combinations.push_back(path);
            return;
        }
        
        string currentLetters = letters[digits[ind]];

        for(char ch:currentLetters){
           path.push_back(ch);
           solve(ind+1, path, digits, letters,combinations);
           path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string>letters;

        letters['2'] = "abc";
        letters['3'] = "def";
        letters['4'] = "ghi";
        letters['5'] = "jkl";
        letters['6'] = "mno";
        letters['7'] = "pqrs";
        letters['8'] = "tuv";
        letters['9'] = "wxyz";

        vector<string>combinations;

        if(digits.length() == 0) return combinations;

        solve(0, "", digits, letters,combinations);

        return combinations;
    }
};