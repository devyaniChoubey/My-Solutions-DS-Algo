https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1

class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string str, string pat)
    {
        // Your code here/
        
        int hash_str[256] = {0};
        int hash_pat[256] = {0};
        
        for(char c:pat) hash_pat[c]++;
        
        int left = 0, right = 0;
        
        int n = str.length();
        int p = pat.length();
        
        if (n < p) return "-1";
        
        int cnt = 0;
        int len = INT_MAX;
        
        int startInd = -1;
        
        while(right < n){
            hash_str[str[right]]++;
            
            if(hash_str[str[right]] <= hash_pat[str[right]]) cnt++;
            
            // if all the characters are matched
            if(cnt == p){
                // Try to minimize the window
                while(hash_str[str[left]] > hash_pat[str[left]] && left < n){
                    hash_str[str[left]]--;
                    left++;
                }
                
                if(len > right - left + 1){
                    len = right - left + 1;
                    startInd = left;
                }
            }
            
            right++;
        }
        
        
        if(startInd == -1) return "-1";
        else return str.substr(startInd, len);
        
        
    }
};
