https://www.interviewbit.com/problems/self-permutation/

int Solution::permuteStrings(string A, string B) {
    vector<int>freq(26, 0);
    
    for(char &c:A) freq[c-'a']++;
    
    for(char &c:B) freq[c-'a']--;
    
    for(int i=0;i < 26;i++) {
        if(freq[i] != 0) return 0;
    }
    
    return 1;
}
