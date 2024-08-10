https://leetcode.com/problems/reverse-vowels-of-a-string/?envType=company&envId=google&favoriteSlug=google-three-months&status=TO_DO%2CATTEMPTED&difficulty=MEDIUM%2CEASY

class Solution {
public:
    bool isVowel(char &c){
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
        return true;
      }

      return false;
    }
    string reverseVowels(string s) {
      int i = 0, j = s.length() - 1;

      while(i <= j){
        while(i < s.length() && !isVowel(s[i])){
          i++;
        }
        
        while(j >= 0 && !isVowel(s[j])){
          j--;
        }

        if(i < j)swap(s[i] , s[j]);
        i++;j--;
      }

      return s;
    }
};