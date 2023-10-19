https://www.interviewbit.com/problems/length-of-last-word/

int Solution::lengthOfLastWord(const string s) {
    int i = s.length() - 1;
    
    while(i >= 0 && s[i] == ' ') i--;
    
    int len = 0;
    
    while(i >= 0 && s[i] != ' ') {
        i--;
        len++;
    }
    
    return len;
    
}
