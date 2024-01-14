https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1

class Solution{
    public:
    int findSubString(string str)
    {
        int left = 0, right = 0;
        int n = str.length();
        
        set<char>st;
        
        for(char c:str) st.insert(c);
        
        int mp[256] = { 0 };
        
        int cnt = 0;
        int len = INT_MAX;
        
        while(right < n){
            mp[str[right]]++;
            
            if(mp[str[right]] == 1) cnt++;
            
            if(cnt == st.size()){
                    while(mp[str[left]] > 1){
                        mp[str[left]]--;
                        left++;
                    }
                
                len = min(len , right - left + 1);
            }
            
            right++;
        }
        
        return len;
    }
};
