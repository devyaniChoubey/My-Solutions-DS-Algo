https://www.naukri.com/code360/problems/print-subsequences_8416366?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

void solve(int ind, vector<string>&ans, string temp, string &s){
    if(ind >= s.length()){
        ans.push_back(temp);
        return;
    }
    
    temp.push_back(s[ind]);
    solve(ind+1, ans,temp, s);
    temp.pop_back();
    solve(ind+1, ans,temp, s);
}

vector<string> generateSubsequences(string s)
{
    // Write your code here.
    vector<string>ans;
    string temp;
    solve(0, ans, temp,s);
    return ans;  
}