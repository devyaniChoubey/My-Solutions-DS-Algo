https://www.interviewbit.com/problems/string-and-its-frequency/

string Solution::solve(string s) {
    vector<int>freq(26, 0);
    string ans = "";
    
    for(char c:s) freq[c-'a']++;
    
    for(char c:s){
        if(freq[c-'a'] > 0){
            ans += c;
            ans += to_string(freq[c-'a']);
            freq[c-'a'] = -1;
        }
    }
    
    return ans;
}
