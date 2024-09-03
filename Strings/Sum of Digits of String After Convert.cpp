https://leetcode.com/problems/sum-of-digits-of-string-after-convert/?envType=daily-question&envId=2024-09-03

class Solution {
public:
    int getLucky(string s, int k) {
        
        string curString = "";

        for(auto &ch:s){
            curString += to_string(ch-'a' + 1);
        }

        while(k--){
            int digitSum = 0;
            for(auto &ch:curString){
               digitSum += (ch - '0');
            }
            curString = to_string(digitSum);
        }

        return stoi(curString);
    }
};


//Solution 2

class Solution {
public:
    int getLucky(string s, int k) {
        
        int currentNumber = 0;
        for(char &c:s){
            int position = c-'a' + 1;
            while(position != 0){
                currentNumber += (position%10);
                position /= 10;
            }
        }
        k--;
        
        while(k > 0){
            int digitSum = 0;

            while(currentNumber != 0){
               digitSum += currentNumber%10;
               currentNumber /= 10;
            }

            currentNumber = digitSum;
            k--;
        }

        return currentNumber;
    }
};