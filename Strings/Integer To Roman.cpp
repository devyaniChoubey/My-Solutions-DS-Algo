https://leetcode.com/problems/integer-to-roman/description/

string Solution::intToRoman(int num) {
    int values[] = {1000 , 900 , 500, 400, 100, 90 , 50 , 40 , 10 , 9, 5, 4, 1};
    string symbols[] = {"M" , "CM" , "D" , "CD" , "C" , "XC", "L" , "XL" , "X" , "IX" , "V" , "IV" , "I"};

    string res = "";

    for(int i=0;i < 13;i++){
        while(values[i] <= num){
            res += symbols[i];
            num -= values[i];
        }
    }

    return res;
}