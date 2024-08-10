https://leetcode.com/problems/valid-word-abbreviation/description/?envType=company&envId=google&favoriteSlug=google-thirty-days&status=TO_DO&difficulty=EASY

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        while (i < word.length() && j < abbr.length()) {
            if (word[i] == abbr[j]) {
                i++;
                j++;
                continue;
            }
            if (abbr[j] <= '0' || abbr[j] > '9') {
                return false;
            }
            int start = j;
            while (j < abbr.length() && abbr[j] >= '0' && abbr[j] <= '9') {
                j++;
            }
            int num = stoi(abbr.substr(start, j - start));
            i += num;
        }
        return i == word.length() && j == abbr.length();
    }
};