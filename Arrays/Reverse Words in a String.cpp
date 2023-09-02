https://leetcode.com/problems/reverse-words-in-a-string/description/


class Solution {
public:
    string reverseWords(string s) {
      stringstream ss(s);

      string temp;

      vector<string>word;

      while(ss >> temp){
        word.push_back(temp);
      }

      temp.clear();

      for(int i=word.size()-1;i >= 0;i--){
        temp.append(word[i]);
        if(i > 0)temp.append(" ");
      }

      

      return temp;
    }
};



//Optimised

class Solution {
public:
    string reverseWords(string s) {
      reverse(s.begin(), s.end());
      int l = 0, r = 0, i = 0, n = s.length();

      while(i < n){
        while(i < n && s[i] != ' '){
          s[r++] = s[i++];
        }

        if(l < r){ // if we can find a non-empty word then
          reverse(s.begin() + l, s.begin() + r); // reverse current word
          s[r] = ' '; // set empty space
          r++; 
          l = r;
        }

        i++; // now i == n or s[i] == ' ', so we skip that character!
      }

      if(r > 0 && s[r-1] == ' ') r--; // skip last empty character if have

      s.resize(r);
       
      return s;

    }
};