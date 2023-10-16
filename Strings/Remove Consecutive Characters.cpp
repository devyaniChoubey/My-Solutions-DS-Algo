https://www.interviewbit.com/problems/remove-consecutive-characters/

string Solution::solve(string s, int k) {
    int count = 1;
    string res = "";
    
    for(int i=1;i < s.length();i++){
        if(s[i-1] == s[i]) count++;
        else{
            if(count != k) res += s.substr(i - count, count);
            count = 1;
        }
    }
    
    if(count != k){
        res += s.substr(s.length() - count, count);
    }
    
    return res;
}