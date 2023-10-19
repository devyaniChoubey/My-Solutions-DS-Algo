https://www.interviewbit.com/problems/reverse-the-string/

string Solution::solve(string s) {
    stringstream ss(s);
    string temp;
    vector<string>parts;
    
    while(getline(ss, temp, ' ')){
        if(!temp.empty())parts.push_back(temp);
    }
    
    string ans = "";
    
    for(int i=parts.size() - 1;i >= 0;i--){
        if(ans.length() > 0) ans += " ";
        ans += parts[i];
    }
    
    return ans;
}

string Solution::solve(string s) {
    string ans = "", cur = "";
    
    for(int i=s.length() - 1;i >= 0;i--){
        if(s[i] == ' '){
            if(cur.length() == 0) continue;
            reverse(cur.begin() , cur.end());
            if(ans.length() > 0) ans += " ";
            ans += cur;
            cur = "";
        }else cur.push_back(s[i]);
    } 
    
    if(cur.length() > 0){
        reverse(cur.begin() , cur.end());
        if(ans.length() > 0) ans += " ";
        ans += cur;
    }
    
    return ans;
}
