https://www.interviewbit.com/problems/longest-substring-without-repeat/

int Solution::lengthOfLongestSubstring(string s) {
    vector<int>seen(256, -1);
    
    int ans = 0;
    
    int startInd = 0;
    
    for(int i=0;i < s.length();i++){
        if(seen[s[i]] >= startInd) startInd = seen[s[i]] + 1;
          
        seen[s[i]] = i;
        
        ans = max(ans, i - startInd + 1);
        
    }
    
    return ans;
}
