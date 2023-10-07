https://www.interviewbit.com/problems/check-palindrome/

int Solution::solve(string s) {
    vector<int>freq(26, 0);
    
    for(char c:s) freq[c - 'a']++;
    
    int oddCount = 0;
    for(auto it:freq){
        if(it % 2 != 0) oddCount++;
    }
    
    int n = s.length();
    
    if((n % 2 == 0 && oddCount == 0) || (n % 2 != 0 && oddCount == 1)) return 1;
    else return 0;
}
